#include<stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, char* argv[]) {
    int a=3, b=4;
    printf("Before swapping a=%d b=%d\n", a, b);
    swap(&a, &b);
    printf("Before swapping a=%d b=%d\n", a, b);
    return 0;
}