#include<stdio.h>

int power(int base, int exponent) {
    int p=1;
    for(int i=0; i<exponent; i++) p*=base;
    return p;
}

int main(int argc, char* argv[]) {
    printf("%d\n", power(3, 4));
    return 0;
}



