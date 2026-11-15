#include<stdio.h>

unsigned long long fibonacci(unsigned int n) {
    if(n == 0) return 0;
    else if(n == 1) return 1;
    else return fibonacci(n-1) + fibonacci(n-2);
}

int main(int argc, char* argv[]) {
    unsigned int n;
    scanf("%u", &n);
    printf("%llu\n", fibonacci(n));
    return 0;
}