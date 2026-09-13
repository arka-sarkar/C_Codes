#include<stdio.h>

int main(int argc, char* argv[]) {
    int A[100]={0};
    int n,i=0;

    do
    {
        scanf("%d",&n);
        if(n<=0) break;
        A[i]=n;
        i++;
    } while (n > 0);
    
    for (i -= 1; i >= 0; i--)
    {
        printf("%d ", A[i]);
    }
    printf("\b\n");
   
    return 0;
}