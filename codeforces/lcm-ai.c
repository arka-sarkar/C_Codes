#include <stdio.h>
#include <string.h>

#define MOD 998244353
#define MAXM 3000

static int start[MAXM + 2];
static int divs[40000];          // flattened divisor lists (about 24k entries)
static int a[MAXM + 1];
static int dp[MAXM + 1], ndp[MAXM + 1];

int main(void) {
    // Precompute divisors of every v in [1, 3000] in CSR form, sorted ascending.
    int cnt[MAXM + 2] = {0};
    for (int d = 1; d <= MAXM; d++)
        for (int v = d; v <= MAXM; v += d) cnt[v]++;

    start[1] = 0;
    for (int v = 1; v <= MAXM; v++) start[v + 1] = start[v] + cnt[v];

    int pos[MAXM + 2];
    for (int v = 1; v <= MAXM; v++) pos[v] = start[v];
    for (int d = 1; d <= MAXM; d++)
        for (int v = d; v <= MAXM; v += d) divs[pos[v]++] = d;

    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        if (a[0] != 0 && a[0] != 1) {
            puts("0");
            continue;
        }

        memset(dp, 0, sizeof(int) * (m + 1));
        dp[1] = 1;

        for (int i = 1; i < n; i++) {
            memset(ndp, 0, sizeof(int) * (m + 1));
            for (int v = 1; v <= m; v++) {
                if (!dp[v]) continue;
                for (int k = start[v]; k < start[v + 1]; k++) {
                    int d = divs[k];
                    if (v + d > m) break;       // divisors are ascending
                    int r = ndp[v + d] + dp[v];
                    if (r >= MOD) r -= MOD;
                    ndp[v + d] = r;
                }
            }
            if (a[i] != 0) {
                for (int v = 1; v <= m; v++)
                    if (v != a[i]) ndp[v] = 0;
            }
            memcpy(dp, ndp, sizeof(int) * (m + 1));
        }

        long long ans = 0;
        for (int v = 1; v <= m; v++) ans += dp[v];
        printf("%lld\n", ans % MOD);
    }
    return 0;
}