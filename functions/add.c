#include<stdio.h>

int add(int a, int b) { return a+b; }

int main(int argc, char* argv[]) {
    int a = add(3,4);
    printf("%d\n",a);
    return 0;
}