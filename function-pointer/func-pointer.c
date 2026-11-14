#include<stdio.h>

int sum(int a, int b) {return a+b;}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int (*fPtr)(int, int);
    fPtr = sum;

    printf("%d\n", sum, fPtr(a, b));

    return 0;
}