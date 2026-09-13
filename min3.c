#include<stdio.h>

int main(int argc, char const *argv[])
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int min;
    if (a <= b) {
        if (a <= c) min = a;
        else min = c;
    } else {
        if (b <= c) min = b;
        else min = c;
    }
    
    printf("\nMin = %d\n",min);
    return 0;
}
