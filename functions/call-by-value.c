#include<stdio.h>

void foo(int x) { x+=10; }

int main(int argc, char* argv[]) {
    int x=5;
    foo(x);
    printf("%d\n", x);
    return 0;
}