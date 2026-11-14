#include<stdio.h>

int main() {
    unsigned short x, part;
    scanf(" %hu", &x);
    for(int i=0; i<=3; i++) {
        part = (x>>(4*i)) & 15u;
        int parity=0;
        for(int j=0; j<=3; j++) parity ^= (unsigned int)((part>>j) & 1u);
        if(parity) printf("%d ", i);
    }
    putchar('\n');
    return 0;
}