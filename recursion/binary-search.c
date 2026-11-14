#include<stdio.h>
#include<stddef.h>

int findIndex(int arr[], int left, int right, int key) {
    if(left > right) return -1;

    int m = left + (right-left)/2;

    if(arr[m] == key) return m;
    else if(key < arr[m]) return findIndex(arr, left, m-1, key);
    else return findIndex(arr, m+1, right, key);
}

int *findIndexPointer(int *left, int *right, int key) {
    if(left > right) return NULL;
    int* m = left + (right - left)/2;
    if(*m == key) return m;
    else if(key < *m) return findIndexPointer(left, m-1, key);
    else return findIndexPointer(m+1, right, key);
}

int main() {
    int n;
    scanf(" %d", &n);
    int num[n];
    for (int i = 0; i < n; i++) scanf(" %d", num+i);
    int key;
    scanf(" %d", &key);
    printf("%d\n", findIndex(num, 0, n-1, key));
    int *p = findIndexPointer(num, num+(n-1), key);
    printf("%td\n", p!=NULL?(p-num):-1);
    return 0;
}