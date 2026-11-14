### Sales Ledger Analysis using an Array of Structs

**Problem Statement**

Define a structure `DailyRecord` that tracks a store's sales over 3 shifts:

```c
struct DailyRecord {
    int day_id;
    int sales[3]; // morning, afternoon, evening
};

```

Write a function:

```c
int find_peak_sales(struct DailyRecord records[], int days, int *peak_day_id);

```

**Requirements:**

* Accept an **array of structures** (`records[]`) and the number of days (`days`).
* Traverse each record's `sales` array using a primitive integer pointer (`int *`), calculating each day's total revenue.
* Identify the day with the highest total sales and store its `day_id` into the integer pointed to by `peak_day_id`.
* Return the maximum total sales value found.
* **Rule:** Do not create or use a pointer to a struct (`struct DailyRecord *`). Only primitive pointers (`int *`) are allowed.

---

### Test Cases

* **Case 1 (Clear winner):**
* **Input:**
* `records = [{id: 101, sales: [120, 200, 150]}, {id: 102, sales: [300, 100, 250]}, {id: 103, sales: [180, 210, 190]}, {id: 104, sales: [220, 140, 110]}]`
* `days = 4`


* **Output:**
* Return value: `650`
* `peak_day_id`: `102`




* **Case 2 (Single day record):**
* **Input:**
* `records = [{id: 501, sales: [50, 60, 40]}]`
* `days = 1`


* **Output:**
* Return value: `150`
* `peak_day_id`: `501`




* **Case 3 (All zero sales):**
* **Input:**
* `records = [{id: 1, sales: [0, 0, 0]}, {id: 2, sales: [0, 0, 0]}]`
* `days = 2`


* **Output:**
* Return value: `0`
* `peak_day_id`: `1`