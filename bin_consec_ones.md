**Contiguous Set Bit Evaluation**

**Problem Statement:**
Construct a function `findMaxConsecutiveOnes` that accepts an unsigned integer and calculates the maximum length of contiguous set bits (1s) within its binary representation. The solution must employ iterative bitwise shift operations or modulo division for sequential bit extraction, determining the maximum sequence length dynamically.

**Constraints:**

* No intermediate data structures (arrays/strings) to hold binary states.
* Must process strictly via scalar bitwise manipulation or base-2 arithmetic.

**Test Cases:**

* **Input:** `156` (Binary: `10011100`) | **Expected Output:** `3`
* **Input:** `43690` (Binary: `1010101010101010`) | **Expected Output:** `1`
* **Input:** `255` (Binary: `11111111`) | **Expected Output:** `8`

