#include<stdio.h>

int main(int argc, char* argv[]) {
    int m,n;
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= 2*m+1; i++)
    {
        for (int j = 1; j <= 2*n+1; j++)
        {
            if (i%2) {
                putchar('0');
            } else {
                if (j%2) putchar('0');
                else putchar('#');
            }
        }
        putchar('\n');
    }
    
    return 0;
}