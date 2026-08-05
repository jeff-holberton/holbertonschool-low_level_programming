# Crash Report

Withing 'crash_example.c' a segmentation fault is present. In this crash report, we are going to discuss the following:
- Where the problem occurs.
- What part of the memory is involved in the crash.
- Possible causes and fixes.

---

## AI DISCLAIMER

This report will also be using one or more LLM to analyse the crash. The result will be reviewed and evaluated accordingly, treating AI generated results as assumptions or speculations.

---

## Localising The Issue

We initialise the following variable
```
|			 |	
| int n = 0; |
|			 |
```
Then we call the following function:
```
|							 |
| nums = allocate_numbers(n) |
|							 |
```
The return value assigned to nums is the address of a newly dynamically allocated array using malloc. However, because n is currently set to 0, we trigger the following condition and return NULL to the pointer:
```
|					|
| if (!arr)			|
|		return NULL;|
|					|
```
Within our main function, we then dereference the pinter "num" with the following statement:
```
|				|
| nums[0] = 0;	|
|				|
```
Causing undefined behavior by writing throguh a NULL pointer.

---

## What Part Of The Memory Is Involved

Often, when having an issue with a pointer's memory allocation, we would be talking about an issue within the Heap. In this specific case however, due to never triggering the malloc() function invocation, the Heap never gets involved.

The Stack is somewhat involved as it contains the actual "num" variable, but the real issue is triggered by trying to dereference a NULL pointer, which triggers a segmentation fault by the operating system, having sensed an access violation.

---

## Possible Fixes

There are a few solutions that could avoid this specific issue, for example by avoiding creating an array of size 0. However, this would not completely remove the possibility of malloc() returning NULL, which would again, cause a segmentation fault.

Instead, the most optimal solution is to check whether the pointer memory allocation was successful, before trying to dereference it.
```
|									|
| nums = allocate_numbers(n);		|
| if (!nums){						|
|	printf("Allocation failed\n");	|
|	return 1;						|
| }									|
```