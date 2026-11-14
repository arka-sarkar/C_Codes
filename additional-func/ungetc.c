#include<stdio.h>

int main() {
    int c;
    c = getchar();
    printf("%c\n", c);
    ungetc(c, stdin);
    c = getchar();
    printf("%c\n", c);
    return 0;
}