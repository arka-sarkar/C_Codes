#include<stdio.h>

int main(int argc, char* argv[]) {
    unsigned int rem, a, b;
    if (scanf("%u %u", &a, &b) != 2) { printf("Please input non-negative integers.\n"); return 1; }
    unsigned int a1=a, b1=b;
    if(b > a) {
        rem = a;
        a = b;
        b = rem;
    }
    while (b != 0)
    {
        rem = a%b;
        a = b;
        b = rem;
    }
    printf("gcd(%u, %u) = %u\n", a1, b1, a);
    return 0;
}