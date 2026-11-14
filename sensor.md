### Multi-Value Return via Pointers with Struct Input

**Problem Statement**

Define a structure `SensorBatch`:

```c
struct SensorBatch {
    int id;
    int readings[6];
};

```

Write a function `void get_reading_extremes(struct SensorBatch b, int total, int *min_out, int *max_out)`:

* `b` must be passed **by value**.
* `min_out` and `max_out` are primitive integer pointers used to return the minimum and maximum values.
* Traverse `b.readings` using a pointer (`const int *curr = b.readings`).

**Test Cases**

* **Case 1 (Mixed values):**
* Input: `readings = [24, -2, 15, 38, -10, 19]`, `total = 6`
* Output: `Min = -10, Max = 38`


* **Case 2 (All identical):**
* Input: `readings = [12, 12, 12, 12, 12, 12]`, `total = 6`
* Output: `Min = 12, Max = 12`


* **Case 3 (Monotonically decreasing):**
* Input: `readings = [50, 40, 30, 20, 10, 0]`, `total = 6`
* Output: `Min = 0, Max = 50`
