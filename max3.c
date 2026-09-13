#include<stdio.h>

int main(int argc, char const *argv[])
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int max = (a>b)?((a>c)?a:c):((b>c)?b:c);
    printf("Max = %d\n", max);
    return 0;
}
