#include<stdio.h>

int sum(int a[], int n) {
    if(n == 1) return a[0];
    return a[n-1] + sum(a, n-1);
}

int main() {
    int a[] = {4, 1, 7};
    printf("%d\n", sum(a, 3));
    return 0;
}