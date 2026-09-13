**The Tournament of Guilds**

Two rival factions, the Lions and the Wolves, are selecting their champions for a grand tournament. The Lions have an array of knight strengths, and the Wolves have their own array of knight strengths.

To determine the maximum number of victories the Lions can secure, they use a tactical pairing strategy:

1. First, the strengths of the knights in both guilds must be sorted in **ascending order**.
2. The Lions then evaluate the matchups sequentially: a Lion can only defeat a Wolf if their strength is **strictly greater** than the Wolf's strength.
3. If a Lion defeats a Wolf, both knights are removed from the roster, and the Lions score a victory. If a Lion is too weak, they step aside, and the next strongest Lion attempts to fight that same Wolf.

**Input:**

* `N`: the number of Lion knights, followed by `N` integers representing their strengths.
* `M`: the number of Wolf knights, followed by `M` integers representing their strengths.

**Output:**
A single integer representing the total number of victories the Lions can secure.

**Requirement:**
You must define and use `sortRoster(int arr[], int size)` and `calculateVictories(int lions[], int n, int wolves[], int m)`. Do not use recursion.

**Example:**
Input:
5
2 9 6 1 8
4
10 5 2 7
Output:
3

*Explanation:*
Sorted Lions: 1, 2, 6, 8, 9
Sorted Wolves: 2, 5, 7, 10

* Lion(1) cannot beat Wolf(2).
* Lion(2) cannot beat Wolf(2).
* Lion(6) beats Wolf(2). (Wins = 1)
* Lion(8) beats Wolf(5). (Wins = 2)
* Lion(9) beats Wolf(7).
Total victories: 3.
