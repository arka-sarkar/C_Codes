#include<stdio.h>
#include<stdlib.h>

long add(int a, int b) { return (long)a+b; }
long sub(int a, int b) { return (long)a-b; }
long mul(int a, int b) { return (long)a*b; }

int main() {
    int n=3;

    long (**operations)(int, int);
    operations = calloc(n, sizeof *operations);

    if(operations == NULL) return EXIT_FAILURE;

    operations[0] = add;
    operations[1] = sub;
    operations[2] = mul;

    for(int i=0; i<n; i++) printf("%ld\n", operations[i](10, 5));
    free(operations);
    return EXIT_SUCCESS;
}