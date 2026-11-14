#include<stdio.h>

int findTheDistanceValue(int* arr1, int arr1Size, int* arr2, int arr2Size, int d) {
    int count=0, satisfy;
    for(int i=0; i<arr1Size; i++) {
        satisfy=1;
        for(int j=0; j<arr2Size; j++) {
            int val = arr1[i]-arr2[j];
            if(val <= d && val >= -d) {
                satisfy=0;
                break;
            }
        }
        if(satisfy) count++;
    }
    return count;
}

int main() {
    int arr1Size, arr2Size;
    scanf(" %d", &arr1Size);
    int arr1[arr1Size];
    for(int i=0; i<arr1Size; i++) scanf(" %d", arr1+i);

    scanf(" %d", &arr2Size);
    int arr2[arr2Size];
    for(int i=0; i<arr2Size; i++) scanf(" %d", arr2+i);
    
    int d;
    scanf(" %d", &d);

    int count=findTheDistanceValue(arr1, arr1Size, arr2, arr2Size, d);
    printf("%d\n", count);
    return 0;
}