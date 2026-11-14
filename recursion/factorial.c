#include<stdio.h>

int factorial(int n, int acc) {
    if(n <= 1) return acc;
    return factorial(n-1, n*acc);
}

int main() {
    printf("%d\n", factorial(10, 1));
    return 0;
}