#include<stdio.h>

void circularShift(unsigned int* n) {
    int val = *n;
    *n = ((val << 1u)|(val>>7u)) & 255u;
}

int main() {
    unsigned int n, min, prev, shifts=0;
    if(scanf("%u", &n) != 1 && n >= 256u) return 1;
    min = n;
    for(int i=1; i<=8; i++) {
        circularShift(&n);
        if(n < min) {
            min=n;
            shifts=i;
        }
    }
    printf("minimum=%u rotations=%u\n", min, shifts);
    return 0;
}