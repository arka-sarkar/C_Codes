#include<stdio.h>

int main(int argc, char* argv[]) {
    int num, even = 0, count = 0;
    for (;; count++)
    {
        scanf(" %d", &num);
        if(num<0) break;
        if(num%2) continue;
        even++;
    }
    
    printf("Even: %d\nOdd: %d\n", even, count-even);

    return 0;
}