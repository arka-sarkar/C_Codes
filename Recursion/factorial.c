#include<stdio.h>

unsigned long long fact(unsigned int n) {
    if(n == 0)
        return 1;
    return (unsigned long long)(n) * fact(n-1);
}

int main(int argc, char* argv[]) {
    unsigned int n;
    scanf("%u", &n);
    printf("%u! = %llu\n", n, fact(n));
    return 0;
}