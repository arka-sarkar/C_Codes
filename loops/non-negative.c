#include<stdio.h>

int main(int argc, char* argv[]) {
    int n;
    scanf("%d",&n);
    int first=1;

    while (n>=0)
    {
        if(first) {
            printf("%d",n);
            first = 0;
        } else {
            printf(" %d",n);
        }
        scanf(" %d", &n);
    }
    
    putchar('\n');
    return 0;
}