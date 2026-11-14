#include<stdio.h>

long long fib(int n, long long dp[]) {
    if(n <= 1) return n;
    if(dp[n] != -1) return dp[n];
    return dp[n] = fib(n-1, dp) + fib(n-2, dp);
}

int main() {
    int n;
    scanf("%d", &n);
    long long dp[n+1];
    for (int i = 0; i <= n; i++) dp[i] = -1;
    
    printf("%lld\n", fib(n, dp));
    return 0;
}