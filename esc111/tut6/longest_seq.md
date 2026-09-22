**Longest Contiguous Character Block**

 Your task is to find the character that forms the longest continuous block of identical consecutive characters. If multiple characters tie for the longest block, print the character whose maximum block appeared first in the string.

**Input:** A single string consisting of lowercase English letters (maximum 100 characters, no spaces).
**Output:** The character and the length of its longest continuous block, separated by a space.

**Test Cases**

| Input | Output | Explanation |
| --- | --- | --- |
| `aabbbcccc` | `c 4` | `a` has a block of 2, `b` has 3, `c` has 4. The longest is `c`. |
| `xyz` | `x 1` | All characters have a max block of 1. `x` is the first to achieve this length. |
| `aabbcc` | `a 2` | `a`, `b`, and `c` all have blocks of length 2. `a` achieved this length first. |
| `abacabaa` | `a 2` | The longest block is `aa` at the end, which is length 2. |
