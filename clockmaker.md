**The Clockmaker’s Secret**

In the village of Chronos, an eccentric clockmaker synchronizes two magical clocks, C1 and C2, during the annual Time Festival. To find the perfect harmony between the two clocks, the clockmaker extracts the "Largest Proper Divisor" (LPD) of each clock's serial number. The LPD is the largest factor of a number excluding the number itself.

Depending on the mystical properties of these LPDs, the clocks will behave differently:

1. **Harmonic Resonance:** If the LPDs of both C1 and C2 are prime numbers, the clocks chime in perfect unison. The resulting festival number is the sum of the two LPDs.
2. **Dissonant Tick:** If exactly one of the LPDs is a prime number, the clocks tick out of phase. The festival number becomes the product of the original serial numbers C1 and C2.
3. **Silence:** If neither LPD is prime, the clocks fall silent. The festival number is the absolute difference between the two LPDs (the larger LPD minus the smaller LPD).

Write a program to automate the clockmaker's calculation.

**Input:**
Two space-separated integers C1 and C2.

**Output:**
A single integer representing the festival number.

**Constraints:**
10 <= C1, C2 <= 1000

**Example 1:**
Input:
14 15
Output:
12

Explanation:
The LPD of 14 is 7 (which is prime). The LPD of 15 is 5 (which is prime). Since both are prime, the answer is 7 + 5 = 12.

**Example 2:**
Input:
12 15
Output:
180

Explanation:
The LPD of 12 is 6 (not prime). The LPD of 15 is 5 (prime). Since exactly one is prime, the answer is C1 * C2 = 12 * 15 = 180.

**IMPORTANT:**
Make sure your code is modular. You must define and use two functions: `getLPD` and `isPrime`.

