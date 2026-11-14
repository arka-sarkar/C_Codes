#include<stdio.h>

int countGoodNumbers(long long n) {
    if(n == 1) return 5;
    else if(n == 2) return 20;
    long long res;
    
    if(n%4==0) {
        int val=countGoodNumbers(n/2);
        res=(long)val*val;
    } else if (n%4 == 2) {
        res = 4ll*countGoodNumbers(n-1);  
    } else if(n%4==3) {
        int val=countGoodNumbers((n-1)/2);
        res=4ll*val*val;
    } else {
        int val=countGoodNumbers((n-1)/2);
        res=5ll*val*val;
    }
    return (int)(res%1000000007ll);
}

int main() {
    long long n;
    scanf(" %lld", &n);
    printf("%d\n", countGoodNumbers(n));
    return 0;
}