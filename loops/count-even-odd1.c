#include<stdio.h>

int main(int argc, char* argv[]) {
    int even, odd, count, val;

    scanf("%d", &count);

    if (count<=0) return 0;
    
    for(even=0,odd=0; count--; even+=1-val%2, odd+=val%2) scanf(" %d", &val);
    printf("Even: %d\nOdd: %d\n", even, odd);

    return 0;
}