#include<stdio.h>

int main() {
    int curr = 0, best=0, start;
    unsigned short n, bit;
    scanf(" %hu", &n);
    for(unsigned int i=0; i<=15; i++) {
        if((n>>i) & 1u) {
            curr++;
            if(curr > best) {
                best=curr;
                start = (i-curr+1);
            }
        } else curr=0;
    }
    printf("length=%d start=%d\n", best, start);
    return 0;
}