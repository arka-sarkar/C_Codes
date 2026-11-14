#include<stdio.h>
#include<stdbool.h>

unsigned int getBit(unsigned int n, unsigned int pos) {
    return (n>>pos)&1u;
}

unsigned int circularLeft(unsigned int n, unsigned int times) {
    for(int i=1; i<=times; i++) n = (n << 1u | n >> 15u) & 65535u;
    return n;
}

bool isPalin(unsigned int n) {
    for(int i=0; i<=7; i++) {
        if(getBit(n,i)!=getBit(n,15-i)) return false;
    }
    return true;
}

int isCircularPalin(unsigned int n) {
    for(int i=0; i<=15; i++) {
        if(isPalin(circularLeft(n, i))) return i;
    }
    return -1;
}

int main() {
    unsigned int n;
    if(scanf(" %u", &n) && n >= 65536u) return 1;
    printf("Palindrome: %s\n", isPalin(n)?"YES":"NO");
    int rot = isCircularPalin(n);
    
    if(rot != -1) printf("Circular Palindrome: YES (rotations=%d value=%d)\n", rot, circularLeft(n, rot));
    else printf("Circular Palindrome: NO\n");

    int min = n, minRot=0;
    for(int i=1; i<=15; i++) {
        int val = circularLeft(n, i);
        if(val < min) {
            min=val;
            minRot=i;
        }
    }
    printf("Canonical: minimum=%d rotations=%d\n", min, minRot);
    return 0;
}