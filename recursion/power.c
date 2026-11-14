#include<stdio.h>

int power(int base, int exp) {
    if(exp == 0) return 1;

    int result;
    if(exp) result = power(base, exp/2);

    if(exp%2 == 0) return result*result;
    else return base*result*result;  
}

int main() {
    printf("%d\n", power(12, 4));
    return 0;
}