**The Wizard's Vault**

A wizard guards his treasure vault with a two-part passcode: P1 and P2. To unlock the vault, the magic mechanism first strips away the "shell" of each passcode to reveal its "Core". The Core is found by mathematically removing the first digit and the last digit of the number. (If the original number has fewer than 3 digits, its Core is 0).

The vault evaluates the strength of each Core:
A Core is considered "Strong" if the sum of its digits is an even number AND greater than 0.

Based on the strength of the Cores, the vault dispenses gold:

1. **Double Jackpot:** If both Cores are Strong, the vault multiplies them. Result = Core1 * Core2.
2. **Standard Bounty:** If exactly one Core is Strong, the vault adds them. Result = Core1 + Core2.
3. **Trap Triggered:** If neither Core is Strong, the vault shuts down. Result = 0.

**Input:**
Two space-separated integers P1 and P2.

**Output:**
A single integer representing the gold dispensed.

**Constraints:**
10 <= P1, P2 <= 99999

**Example 1:**
Input:
2621 8119
Output:
682

Explanation:
Core of 2621 is 62. The sum of digits is 6+2 = 8 (Even -> Strong).
Core of 8119 is 11. The sum of digits is 1+1 = 2 (Even -> Strong).
Both are strong, so the answer is 62 * 11 = 682.

**Example 2:**
Input:
4452 123
Output:
47

Explanation:
Core of 4452 is 45. Sum is 4+5 = 9 (Odd -> Not Strong).
Core of 123 is 2. Sum is 2 (Even -> Strong).
Exactly one is strong, so the answer is 45 + 2 = 47.

**IMPORTANT:**
You must define and use two functions: `extractCore` and `isStrong`. You cannot use arrays or strings to strip the digits.
