#include<stdio.h>

int main(int argc, char const *argv[])
{
    int a,b;
    scanf("%d %d", &a, &b);
    int max = ( a > b ) ? a : b;
    printf("The greater term is %d\n", max);
    return 0;
}
