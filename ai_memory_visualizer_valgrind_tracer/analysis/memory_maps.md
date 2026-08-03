# Step-by-Step Memory Maps

Conventions used throughout:
- Stack grows **downward** (toward lower addresses); the most recently pushed frame is drawn at the bottom.
- Heap addresses are shown as symbolic labels (`H1`, `P1`, `N1`, ...) standing in for whatever the allocator actually hands back.
- `?` means "uninitialized / indeterminate contents."
- Each program's bug is called out explicitly, with the diagnostic a tool like Valgrind or a debugger would report.

# Disclaimer

AI was used in the making of this analysis. The LLM was given precise writing conditions and supplied the programs to analise. This was done after thoroguh review of the code, as well as compilation results. No changes have been made to the analysis reported by the AI model, the report is consistent with my own findings and deductions. The report was also cross reviewed by a second LLM, to check if there might be anything I was missing personally; the result seemed consistent with both previous analyses.

---

## 1. `aliasing_example.c` — aliasing + use-after-free

### Frame layout
- `main()`: `a` (int*), `b` (int*), `n` (int)
- `make_numbers(n)`: `i` (int), `arr` (int*), param `n`

### Trace

**Step 1 — `main()` calls `make_numbers(5)`**
```
STACK                              HEAP
┌─────────────────────┐
│ main                │
│  a = NULL           │
│  b = NULL           │
│  n = 5              │
├─────────────────────┤
│ make_numbers(5)     │
│  n(param) = 5       │            (nothing allocated yet)
│  i = 0              │
│  arr = NULL         │
└─────────────────────┘
```

**Step 2 — `malloc(5 * sizeof(int))` succeeds**
```
STACK                              HEAP
│ make_numbers        │            ┌──────────────┐
│  arr = H1  ─────────┼───────────▶│ H1: int[5]   │
│                      │            │  ? ? ? ? ?   │
```

**Step 3 — loop fills the array (`arr[i] = i*11`)**
```
HEAP
┌───────────────────────────┐
│ H1: [0, 11, 22, 33, 44]   │
└───────────────────────────┘
```

**Step 4 — `return arr;` → `make_numbers` frame is popped**
```
STACK                              HEAP
┌─────────────────────┐            ┌───────────────────────────┐
│ main                │            │ H1: [0, 11, 22, 33, 44]   │
│  a = NULL           │            └───────────────────────────┘
│  b = NULL           │
│  n = 5              │
└─────────────────────┘
(make_numbers frame gone; H1's address was copied out as the return value)
```

**Step 5 — `a = make_numbers(n)`**
```
main: a = H1, b = NULL, n = 5
```

**Step 6 — `b = a;`  ← aliasing happens here**
```
main: a = H1, b = H1
```
`a` and `b` are now two independent stack variables pointing at the **same** heap object. There is exactly one heap block, with two aliases.

**Step 7 — `a[2]` / `b[2]` read (both = 22)** — legal, both aliases valid.

**Step 8 — `free(a);`**
```
HEAP
┌───────────────────────────┐
│ H1: FREED                 │   ← allocator may reuse/scribble this block
└───────────────────────────┘
STACK: a = H1 (dangling), b = H1 (dangling)
```
Freeing through `a` does not change `a` or `b`'s stored address — it only tells the allocator the block is available. Both pointers are now **dangling**.

**Step 9 — print `b` (still prints the old address, now meaningless as a live pointer)**

**Step 10 — `b[2]` read** → **use-after-free read**. Valgrind: `Invalid read of size 4`, pointing at the `free(a)` call as the location the block was released.

**Step 11 — `b[3] = 1234;`** → **use-after-free write**. Valgrind: `Invalid write of size 4`.

### Pointer/alias table
| Variable | Value | Notes |
|---|---|---|
| `a` | `H1` | dangling after step 8 |
| `b` | `H1` | alias of `a`; dangling after step 8 |

### Object lifetime
| Object | Born | Died | Notes |
|---|---|---|---|
| `H1` (`int[5]`) | `malloc` in `make_numbers` | `free(a)` | Referenced (illegally) via `b` **after** death — the lifetime violation the example is built to demonstrate |

---

## 2. `crash_example.c` — deterministic NULL dereference

### Frame layout
- `main()`: `nums` (int*), `n` (int)
- `allocate_numbers(n)`: `arr` (int*), `i` (int), param `n`

### Trace

**Step 1 — `main()` calls `allocate_numbers(0)`**
```
STACK                              HEAP
│ main                │
│  nums = NULL        │
│  n = 0              │            (empty — nothing will be allocated)
├─────────────────────┤
│ allocate_numbers    │
│  n(param) = 0       │
│  arr = NULL         │
│  i = 0              │
```

**Step 2 — `if (n <= 0) return NULL;` fires immediately**
No `malloc` ever executes. The heap map for this program is **empty for the entire run**.
```
allocate_numbers frame popped, returns NULL
```

**Step 3 — back in `main`: `nums = NULL`**
```
main: nums = NULL, n = 0
```

**Step 4 — `nums[0] = 42;`**
This is `*(nums + 0) = 42`, i.e. a write through address `0x0`. The MMU has no mapping for page 0, so the CPU raises a fault the OS turns into `SIGSEGV`.
```
STACK                              HEAP
│ main                │
│  nums = NULL  ──────┼──▶ (address 0x0, unmapped)  ✕ SEGFAULT
```
The process terminates immediately at this line. `free(nums)` is never reached — there's nothing to free anyway.

### Object lifetime
**None created.** The bug isn't a lifetime violation but a missing NULL-check: the caller never verifies `allocate_numbers`'s return value before dereferencing it.

---

## 3. `heap_example.c` — nested heap allocation + deliberate leak

`Person` is a two-level heap structure: the struct itself, plus a separately-allocated name string reached through `p->name`.

### Trace

**Step 1 — `person_new("Alice", 30)`**
```
HEAP
┌───────────────────┐        ┌───────────────┐
│ P1: Person        │        │ N1: "Alice\0" │
│  name ───────────┼───────▶│               │
│  age  = 30        │        └───────────────┘
└───────────────────┘
STACK: main: alice = P1
```

**Step 2 — `person_new("Bob", 41)`**
```
HEAP
┌───────────────────┐        ┌───────────────┐
│ P1: Person        │───────▶│ N1: "Alice"   │
│  age=30           │        └───────────────┘
├───────────────────┤        ┌───────────────┐
│ P2: Person        │───────▶│ N2: "Bob\0"   │
│  age=41           │        └───────────────┘
└───────────────────┘
STACK: main: alice = P1, bob = P2
```

**Step 3 — prints read `alice->name` (N1) and `bob->name` (N2)** — no changes to memory.

**Step 4 — `free(bob->name);`** → `N2` freed
```
HEAP: [P1]→[N1 "Alice"]   [P2 age=41]   [N2: FREED]
```

**Step 5 — `free(bob);`** → `P2` freed. Correct order: the pointed-to string was freed *before* the struct that held the only pointer to it, so nothing is leaked for Bob.
```
HEAP: [P1]→[N1 "Alice"]   [P2: FREED]   [N2: FREED]
```
`bob` (the stack variable) still holds `P2`'s old address but is never dereferenced again — dangling but harmless.

**Step 6 — `person_free_partial(alice);`** → only calls `free(p)`, i.e. `free(P1)`. **`alice->name` (N1) is never freed.**
```
HEAP
┌───────────────┐
│ P1: FREED     │
└───────────────┘
┌───────────────┐
│ N1: "Alice"   │   ← still allocated, but no live pointer anywhere reaches it anymore
└───────────────┘   ← MEMORY LEAK
```
The instant `P1` is freed, the only pointer that ever pointed at `N1` (`P1->name`) is gone — the string is now unreachable but still occupies the heap.

**Step 7 — `main` returns.** Program exits with `N1` still allocated and unreferenced.

### Object lifetime table
| Object | Born | Died | Outcome |
|---|---|---|---|
| `P1` (Alice struct) | step 1 | step 6 | freed |
| `N1` ("Alice") | step 1 | **never** | **leaked** (definitely-lost, per Valgrind) |
| `P2` (Bob struct) | step 2 | step 5 | freed |
| `N2` ("Bob") | step 2 | step 4 | freed correctly, in proper order |

The asymmetry is the whole point of the example: `bob`'s cleanup frees inner-then-outer correctly, while `alice`'s cleanup (`person_free_partial`) only frees the outer struct, leaking the inner string.

---

## 4. `stack_example.c` — recursion and stack-frame reuse

`walk_stack(0, 3)` recurses down to depth 3, then unwinds, calling `dump_frame` on both the way down (`"enter"`) and the way back up (`"exit"`).

### Trace (stack drawn growing downward; each new frame sits below/inside the caller's)

**Descent — depth 0 → 3**
```
main
└─ walk_stack(depth=0)      marker=0
   └─ dump_frame("enter",0) local_int=100 local_buf="A"   [frame popped after call]
   └─ walk_stack(depth=1)   marker=10
      └─ dump_frame("enter",1) local_int=101 local_buf="B" [popped]
      └─ walk_stack(depth=2)  marker=20
         └─ dump_frame("enter",2) local_int=102 local_buf="C" [popped]
         └─ walk_stack(depth=3)  marker=30      ← deepest frame
            └─ dump_frame("enter",3) local_int=103 local_buf="D" [popped]
            (depth == max_depth: base case, no further recursion)
```
At the deepest point, the stack literally contains: `main` → `walk_stack(0)` → `walk_stack(1)` → `walk_stack(2)` → `walk_stack(3)`, five frames stacked at successively lower addresses. Each `dump_frame` call briefly adds and removes one more frame below whichever `walk_stack` frame invoked it.

**Unwind — depth 3 → 0**
```
walk_stack(depth=3):
  dump_frame("exit",3)   ← a *new* dump_frame call: fresh local_int=103, fresh local_buf="D"
  returns → walk_stack(2) resumes

walk_stack(depth=2):
  dump_frame("exit",2)   local_int=102, local_buf="C"
  returns → walk_stack(1) resumes

walk_stack(depth=1):
  dump_frame("exit",1)   local_int=101, local_buf="B"
  returns → walk_stack(0) resumes

walk_stack(depth=0):
  dump_frame("exit",0)   local_int=100, local_buf="A"
  returns → main resumes
```

### Key observations
- **Each `dump_frame` invocation gets brand-new stack memory** for `local_int`, `local_buf`, and `p_local` — the "enter" and "exit" calls at the *same* depth are unrelated invocations that happen to compute the same values, not the same variables persisting.
- Because the stack is LIFO, the `"exit"` `dump_frame` call at depth *N* is typically allocated at **the same address** as the `"enter"` `dump_frame` call at depth *N* (or very close to it) — once everything pushed after that point (deeper recursion, the deeper `dump_frame` calls) has been popped, the stack pointer is back where it was, so the next frame reuses the same bytes. This is the classic reason uninitialized/freed stack memory can appear to "remember" old values.
- `marker` in each `walk_stack` frame stays alive for the *entire* time that frame is on the stack, including while all of its recursive children are executing — it's below `walk_stack(N+1)`'s frame, not destroyed by it.
- `&local_int` addresses strictly decrease as depth increases (each recursive call's frame sits at a lower address than its caller's), then the same sequence of addresses is revisited in reverse on the way back up.

### Object lifetime table
| Object | Scope | Lifetime |
|---|---|---|
| `walk_stack(N)`'s `marker` | one recursion level | from entry to that call until it returns (spans all deeper recursive calls) |
| `dump_frame`'s `local_int`, `local_buf`, `p_local` | one `dump_frame` call | created on entry, destroyed on return — a fresh instance each of the 8 times `dump_frame` is called (4 "enter" + 4 "exit") |

---

## Summary of bugs / tool findings

| Program | Bug class | What a tool reports |
|---|---|---|
| `aliasing_example.c` | use-after-free (read + write) via an aliased pointer | Valgrind: `Invalid read/write of size 4`, "Address ... is 0 bytes inside a block of size 20 free'd" |
| `crash_example.c` | NULL-pointer dereference | OS/debugger: `SIGSEGV` at the `nums[0] = 42;` line |
| `heap_example.c` | memory leak (inner allocation freed by outer struct only) | Valgrind: `... bytes in 1 blocks are definitely lost` for `N1` |
| `stack_example.c` | none (correct code) — used to illustrate stack growth/frame reuse | n/a — a good contrast case showing what *valid* stack lifetime looks like |

