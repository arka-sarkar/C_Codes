### In-Place Array Shift Using Pointer Arithmetic

**Problem Statement**

Write a function `void circular_left_shift(int *arr, int size, int k)` that shifts all elements in an integer array `k (k<size)` position to the left. The first element should wrap around and move to the corresponding position.

* Do not use array bracket indexing (`[]`) inside the function.
* Use only pointers and pointer arithmetic (`*`, `+`, `++`).

**Test Cases**

* **Case 1 (Standard):**
* Input: `arr = [10, 20, 30, 40, 50]`, `size = 5`, `k=2`
* Output: `[30, 40, 50, 10, 20]`


* **Case 2 (Two elements):**
* Input: `arr = [1, 2]`, `size = 2`, `k=1`
* Output: `[2, 1]`


* **Case 3 (Single element):**
* Input: `arr = [99]`, `size = 1` `k=1`
* Output: `[99]`

