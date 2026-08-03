# Valgrind Analysis

In this analysis we will be:
- Classify each Valgrind warning.
- Map each warning to a specific memory misuse.
- Use precise terminology.
- Include at least one instance where:
  - An AI explanation was partially or fully incorrect.
  - We explain why it is incorrect

# Disclaimer

AI was used in the making of this analysis. The LLM was given precise writing conditions and supplied the programs to analise. This was done after thoroguh review of the code, as well as compilation results. No changes have been made to the analysis reported by the AI model, the report is consistent with my own findings and deductions. The report was also cross reviewed by a second LLM, to check if there might be anything I was missing personally; the result seemed consistent with both previous analyses.

---

## 1. `aliasing_example.c` 

### Valgrind Warnings

After calling "free(a)" we are presented with the following warnings:
- Invalid read of size 4: when printing b[2], we're trying to read the value of an address that has been previously freed in "free(a).
- Invalid write of size 4: when executing "b[3] = 1234", we are trying to write a value in an address that has been freed previously, potentially overwriting some data that we don't own.
- Invalid read of size 4: again, printing b[3], causing the same issue.

All of these warnings are use-after-free errors.

---

## 2. `crash_example.c` 

The cause of the issue is not checking whether we were successful in allocating memory to our pointer. Our function returns NULL, and no check is made before interacting with our pointer, causing a segmentation fault by accessing un-mapped memory.

- Invalid write of size 4: "num[0] = 42", address is not stack'd, malloc'd or (recently) free'd. Dumping core. (Illegal write error)

---

## 3. 'heap_example.c'

The issue is a heap leak, caused by partially free()ing a previously malloc'd data structure (without free()ing the pointer contained within).

- HEAP SUMMARY: in use at exit: 6 bytes in 1 blocks, definitely lost. Leak due to lost ownership

---

## 4. 'stack_example.c'

No memory errors detected.

- All heap blocs were freed -- no leaks are possible.