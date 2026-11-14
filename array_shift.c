#include<stdio.h>

void circular_left_shift(int *arr, int size, int k) {
    int index;
    int arr1[k];

    for(int i = 0; i < k; i++) {
        *(arr1+i) = *(arr+i);
    }

    for(int i = 0; i < size; i++) {
        index = (i+k) % size;
        *(arr+i) = *(arr+index);
    }

    for(int i = 0; i < k; i++) {
        *(arr+(size-k+i)) = *(arr1+i);
    }
}

int main() {
    int size, k;
    scanf(" %d", &size);
    int num[size];

    for(int i = 0; i < size; i++) scanf(" %d", num+i);
    scanf(" %d", &k);
    circular_left_shift(num, size, k);

    for(int i = 0; i < size; i++) {
        if(i == 0) printf("[%d", *num);
        else printf(", %d", *(num+i));
    }
    printf("]\n");
    return 0;
}