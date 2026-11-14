#include<stdio.h>

int main() {
    unsigned int n, bit, start1, start0, prev;
    int set_bits=0, curr1=0, best1=0, xor_bit=0, transitions = 0, curr0=0, best0=0;
    if(scanf(" %u", &n) && n >= 65536u) return 1;
    if(n==0) {
        set_bits=0;
        best1=0;
        start1=-1;
        best0=16;
        start0=0;
    } else if(n==65535) {
        set_bits=16;
        best1=16;
        start1=0;
        best0=0;
        start0=-1;
    } else {
        for(int i=0; i<=15; i++) {
            bit = (n>>i) & 1u;
            if(i >= 1 && (prev^bit)==1) transitions++;
            xor_bit ^= bit;
            set_bits += bit;
            if(bit) {
                curr0=0;
                curr1++;
                if(curr1 > best1) {
                    best1=curr1;
                    start1=i-curr1+1;
                }
            } else {
                curr1=0;
                curr0++;
                if(curr0 > best0) {
                    best0 = curr0;
                    start0 = i-curr0+1;
                }
            }
            prev = bit;
        }
    }
    
    printf("1-bits: count=%d parity=%s\n", set_bits, set_bits%2?"ODD":"EVEN");
    printf("Longest 1-run: length=%d start=%d\n", best1, start1);
    printf("Longest 0-run: length=%d start=%d\n", best0, start0);
    printf("Transitions: %d\n", transitions); 
    return 0;
}