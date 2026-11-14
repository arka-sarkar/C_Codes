#include<stdio.h>

int f(int n, int dp[]) {
    if (n == 0) return 0;
    if(dp[n] != -1) return dp[n];
    return dp[n] = n + f(n - 1, dp) + f(n - 2 < 0 ? 0 : n - 2, dp);
}

int main() {
    int dp[4] = {-1, -1, -1, -1};
    printf("%d\n", f(3, dp));
    return 0;
}