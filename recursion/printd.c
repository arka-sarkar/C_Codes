#include<stdio.h>

void printd(int num) {
    if(num < 0) {
        putchar('-');
        num = -num;
    }
    if(num/10) {
        printd(num/10);
    }
    putchar(num%10 + '0');
}

int main() {
    printd(-445);
    putchar('\n');
    return 0;
}