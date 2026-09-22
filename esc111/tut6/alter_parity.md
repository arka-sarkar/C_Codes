**Longest Alternating Parity Segment**

Instead of just checking if a value is strictly increasing, this problem requires tracking the mathematical properties of adjacent elements. You are given an array of $N$ integers. Find the length of the longest contiguous segment where every adjacent pair alternates in parity (odd, even, odd, even, etc.).

**Input:** An integer $N$, followed by $N$ space-separated integers.
**Output:** A single integer representing the maximum alternating segment length.

**Test Cases**

| Input | Output | Explanation |
| --- | --- | --- |
| `7 2 4 5 8 9 10 2` | `5` | The segment `4 5 8 9 10` alternates (E-O-E-O-E). Length is 5. |
| `4 2 4 6 8` | `1` | All elements are even. Max alternating segment length is 1. |
| `5 1 2 3 4 5` | `5` | The entire array alternates. |