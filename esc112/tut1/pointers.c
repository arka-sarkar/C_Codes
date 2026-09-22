#include<stdio.h>
#include<stdint.h>

int main(int argc, char* argv[]) {
    uint64_t a = UINT64_MAX;
    uint64_t* A = &a;
    char* c = (char*) A;

    printf("%p %llu %c\n", A, a, *c);
    return 0;
}