#include<stdio.h>

typedef union data {
    int i;
    float f;
    char c;
} Data;


int main(int argc, char* argv[]) {
    Data d;
    d.i = 10;
    printf("%d\n", d.i);

    d.f = 3.14;
    printf("%.2f\n", d.f);

    d.c = 'a';
    printf("%c\n", d.c);
    printf("%.2f\n", d.f);
    printf("%d\n", d.i);

    return 0;
}