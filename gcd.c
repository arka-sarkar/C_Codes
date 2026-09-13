#include<stdio.h>

unsigned int GCD(unsigned int a,unsigned int b) {
    if ( a % b == 0) return b;
    else if (b % a == 0) return a;
    else if (a > b) return GCD(b, a % b);
    else return GCD(b % a, a);
}

int main(int argc, char* argv[]) {
    unsigned int a, b, gcd;
    if (scanf("%u %u", &a, &b) != 2) { printf("Please input non-negative integers.\n"); return 1;}
    gcd = GCD(a, b);
    printf("gcd(%u, %u) = %u\n", a, b, gcd);
    return 0;
}