**The Knight's Battalion**

A commander organizes soldiers into two battalions, represented by two arrays of integers (power levels). To evaluate combat readiness, the commander strips away the "flanks" of each battalion to reveal its "Core." The Core is evaluated by ignoring the first and last soldier in the array (if a battalion has fewer than 3 soldiers, its Core is empty and has a sum of 0).

The commander evaluates the strength of each Core:
A Core is considered "Elite" if the number of even-powered soldiers in the Core is strictly greater than the number of odd-powered soldiers.

Based on the Elite status, the army's Total Power is calculated:

1. **Flawless Victory:** If both Cores are Elite, multiply the sum of Core 1 by the sum of Core 2.
2. **Standard Advance:** If exactly one Core is Elite, add the sum of Core 1 and the sum of Core 2.
3. **Retreat:** If neither Core is Elite, the Total Power is 0.

**Input:**

* `N1`: size of the first array, followed by `N1` integers.
* `N2`: size of the second array, followed by `N2` integers.

**Output:** A single integer representing the Total Power.
**Requirement:** Define and use `getCoreSum(int arr[], int size)` and `isElite(int arr[], int size)`.