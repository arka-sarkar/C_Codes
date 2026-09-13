#include<stdio.h>
#ifndef LOWER
#define LOWER 0
#endif

#ifndef UPPER
#define UPPER 300
#endif

#ifndef STEP
#define STEP 20
#endif

int main(int argc, char* argv[]) {
    float celsius;
    printf("  F\t  C\n\n");
    for (int fahr = LOWER; fahr <= UPPER; fahr += STEP) {
        celsius = (5.0*(fahr - 32))/9;
        printf("%3d\t%6.1f\n", fahr, celsius);
    }
    
    return 0;
}
