#include<stdio.h>

int main() {
    unsigned int n, l, r;
    scanf(" %hu %hu %hu", &n, &l, &r);
    while(l < r) {
        unsigned short a = (n >> l) & 1u, b = (n >> r) & 1u;
        if(a != b) n ^= (1u << l)|(1u << r);
        l++;
        r--;
    }
    printf("%hu\n", n);
    return 0;
}