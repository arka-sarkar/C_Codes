#include<stdio.h>

int main(int argc, char* argv[]) {
    int a[100]={0};

    int i=0, count=0, countprev, countfinal=0;

    do {
        scanf("%d",a+i);
        i++;
    } while (a[i]!=-1);

    printf("%d\n",i);
    for (int j = 0; j <= i-1; j++)
    {
        printf("%d ",a[j]);
        if(a[j+1] > a[j]) count++;
        else {
            countprev = count;
            count = 0;
            if(countfinal < countprev) countfinal = countprev; 
        }
    }
    

    printf("\b\nLongest length among all increasing subsequences: %d\n", countfinal);
    return 0;
}