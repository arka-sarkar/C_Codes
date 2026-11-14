#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

int divide(int dividend, int divisor) {
    if(dividend == divisor) return 1;
    else if(dividend == INT_MIN && divisor==-1) return INT_MAX;
    else if (divisor == 1) return dividend;
    int sign = (dividend < 0)^(divisor < 0) ? -1:1;

    long a = labs(dividend);
    long b = labs(divisor);

    int quotient = 0, p=0;
    for(;(b<<p)<=a;p++);
    p--;
    int rem = a - (b<<p);
    quotient += (1<<p);

    while(rem-b>=0) {
        quotient++;
        rem -= b;
    }
    
    if(sign==-1) quotient=-quotient; 

    return quotient;
}

int main() {
    int a, b;
    scanf(" %d %d", &a, &b);
    printf("%d\n", divide(a, b));
    return 0;
}