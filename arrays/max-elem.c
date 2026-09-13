#include<stdio.h>

int main(int argc, char* argv[]) {
    int a[5]={4, 9, 2, 7, 5};
    int b[5]={6, 3, 8, 1, 5};
    int c[5];
    for (int i = 0; i < 5; i++) c[i]=(a[i]>b[i])?a[i]:b[i];
    for (int i = 0; i < 5; i++) {
        if(i > 0) putchar(' ');
        printf("%d",*(c+i));
    }
    putchar('\n');
    return 0;
}