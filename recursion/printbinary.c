#include<stdio.h>

void printBinary(int n) {
    if(n == 0) return;
    printBinary(n/2);
    printf("%d", n%2);
}

int main() {
    int n;
    scanf(" %d", &n);
    printBinary(n);
    putchar('\n');
    return 0;
}