#include<stdio.h>
#include<limits.h>
#include<math.h>

int mySqrt(int x) {
    if(x == 0 || x==1) return x;
    if(x == INT_MAX) return 46340;
    float curr=x/1.5, prev;
    do {
        prev = curr;
        curr = (prev*prev+x)/(2.0*prev);
    } while(fabsf(prev-curr)>1);
    int ans = (int)curr;
    if(ans*ans>x) {
        while(ans*ans>x) ans--;
    } else if(ans*ans<x) {
        while(ans*ans<x) ans++;
        ans--;
    }
    return ans;
}

int main() {
    int n;
    scanf(" %d", &n);
    int val = mySqrt(n);
    printf("%d\n", val);
    return 0;
}