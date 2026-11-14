#include<stdio.h>
#include<stdlib.h>

int findIndexLeft(int arr[], int left, int right, int key) {
    if(left > right) return -1;

    int m = (left + right)/2;

    if(arr[m] == key) {
        int r = findIndexLeft(arr, left, m-1, key);
        if(r != -1) return r;
        return m;
    } else if(key < arr[m]) return findIndexLeft(arr, left, m-1, key);
    else return findIndexLeft(arr, m+1, right, key);
}

int findIndexRight(int arr[], int left, int right, int key) {
    if(left > right) return -1;

    int m = (left + right)/2;

    if(arr[m] == key) {
        int r = findIndexRight(arr, m+1, right, key);
        if(r != -1) return r;
        return m;
    } else if(key < arr[m]) return findIndexRight(arr, left, m-1, key);
    else return findIndexRight(arr, m+1, right, key);
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int *range = calloc(2, sizeof(int));

    range[0] = findIndexLeft(nums, 0, numsSize-1, target);
    range[1] = findIndexRight(nums, 0, numsSize-1, target);
    *returnSize = 2;
    return range;
}

int main() {
    int returnSize;
    int numSize;
    scanf(" %d", &numSize);
    int nums[numSize];
    for(int i=0; i<numSize; i++) scanf(" %d", nums+i);

    int target;
    scanf(" %d", &target);

    int *range = searchRange(nums, numSize, target, &returnSize);

    printf("[%d,%d]\n", range[0], range[1]);

    return 0;
}