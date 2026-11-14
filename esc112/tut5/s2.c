#include<stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int hoarePartititon(int a[], int lo, int hi, int *swaps) {
    int pivot = a[lo];
    int i = lo-1;
    int j = hi+1;
    while (1) {
        do{i++;} while (a[i] < pivot);
        do{j--;} while (a[j] > pivot);
        if(i >= j) return j;
        (*swaps)++;
        swap(a+i, a+j);
    }
}

void quickSort(int a[], int lo, int hi, int n, int depth, int *calls, int *maxdepth, int *swaps) {
    (*calls)++;
    if(depth > (*maxdepth)) *maxdepth = depth;
    if(lo >= hi) return;
    // Range [<lo>..<hi>] partitioned at j = <p>: <array_state>

    int p = hoarePartititon(a, lo, hi, swaps);
    printf("Range [%d..%d] partitioned at j = %d:", lo, hi, p);
    for(int i = 0; i < n; i++) printf(" %d", a[i]);
    putchar('\n');
    quickSort(a, lo, p, n, depth+1, calls, maxdepth, swaps);
    quickSort(a, p+1, hi, n, depth+1, calls, maxdepth, swaps);
}

int main() {
    int calls = 0, max_depth = 0, swaps = 0, n;
    scanf(" %d", &n);
    int num[n];
    for (int i = 0; i < n; i++) scanf(" %d", num+i);
    printf("Initial:");
    for (int i = 0; i < n; i++) printf(" %d", num[i]);
    putchar('\n');
    quickSort(num, 0, n-1, n, 1, &calls, &max_depth, &swaps);
    printf("Sorted:");
    for (int i = 0; i < n; i++) printf(" %d", num[i]);
    putchar('\n');
    printf("Total calls: %d, Max depth: %d, Total swaps: %d\n", calls, max_depth, swaps);
    return 0;
}