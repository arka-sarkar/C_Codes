#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int a[], int pos1, int pos2) {
    int temp = a[pos1];
    a[pos1] = a[pos2];
    a[pos2] = temp;
}

int partition(int a[], int p, int r) {
    int pivot_index = (random()%(r-p+1))+p;
    swap(a, pivot_index, r);
    int pivot = a[r];
    int i = p-1;

    for (int j = p; j < r; j++) {
        if(a[j] <= pivot) swap(a, j, ++i);
    }
    swap(a, i+1, r);
    return i+1;
}

void quicksort(int a[], int p, int r) {
    if(p < r) {
        int q = partition(a, p, r);
        quicksort(a, p, q-1);
        quicksort(a, q+1, r);
    }
}

int main() {
    srandom(time(NULL));
    int num[] = {2, 1, 7, 8, 3, 5, 6, 4};
    quicksort(num, 0, 7);
    for (int i = 0; i < 8; i++) {
        if(i != 0) putchar(' ');
        printf("%d", num[i]);
    }
    putchar('\n');
    return 0;
}