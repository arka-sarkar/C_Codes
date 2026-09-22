**Problem: The Great Sorting Showdown**

You are tasked with comparing how three different sorting algorithms move data to achieve the exact same result. You will implement Bubble Sort, Selection Sort, and Insertion Sort. Because passing an array to a function allows it to modify the original data, you must make sure to test each algorithm on a fresh copy of the original unsorted array.

For each algorithm, track and print the total number of "swaps" (or shifts, in the case of Insertion Sort) required to sort the array, followed by the sorted result.

* **Bubble Sort:** Increment your counter every time you swap adjacent elements.


* **Selection Sort:** Increment your counter every time you swap the minimum element into the sorted prefix.


* **Insertion Sort:** Increment your counter every time you shift a larger element to the right to make room for the inserted element.



**Test Cases**

| Input Array | Bubble Swaps | Selection Swaps | Insertion Shifts | Sorted Output |
| --- | --- | --- | --- | --- |
| `5 1 4 2 8` | 4 | 2 | 4 | `1 2 4 5 8` |
| `1 2 3 4 5` | 0 | 0 | 0 | `1 2 3 4 5` |
| `5 4 3 2 1` | 10 | 2 | 10 | `1 2 3 4 5` |
