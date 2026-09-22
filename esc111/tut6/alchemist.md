**The Alchemist's Mixture**

An alchemist mixes two potions, each represented by an array of integers (ingredient potencies). To find the true nature of a potion, the alchemist filters out the "toxins" to create a "Pure Extract". A Pure Extract is formed by copying over only the strictly positive, even integers into a new array.

The alchemist tests the volatility of each Pure Extract:
A Pure Extract is "Volatile" if it contains at least 3 ingredients AND its elements sum to a multiple of 5.

Based on volatility, the resulting reaction yields energy:
 
1. **Explosion:** If both Extracts are Volatile, the energy is the product of their lengths (number of ingredients in the extracts).
2. **Simmer:** If exactly one is Volatile, the energy is the absolute difference of their lengths.
3. **Dud:** If neither is Volatile, the energy is 0.

**Input:**

* `N1`: size of potion 1, followed by `N1` integers.
* `N2`: size of potion 2, followed by `N2` integers.

**Output:** A single integer representing the reaction energy.
**Requirement:** Define and use `filterToxins(int raw[], int size, int pure[], int *pureSize)` and `isVolatile(int pure[], int pureSize)`.