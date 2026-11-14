#include<stdio.h>

void printChar(char c, int k) {
    if(k <= 0) return;
    putchar(c);
    printChar(c, k-1);
}

void printRow(int row, int n) {
    printChar(' ', row-1);
    printChar('*', 2*(n-row)+1);
    putchar('\n');
}

void printDiamond(int row, int n) {
    if(row > n) return;
    printRow(row, n);
    printDiamond(row+1, n);
    if(row < n) printRow(row, n);
}
int main() {
    int n;
    scanf("%d", &n);
    printDiamond(1, n);
    return 0;
}