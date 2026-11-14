#include<stdio.h>

long long absl(long long n) { return (n>0)?n:-n; }

long long GCD(long long a, long long b, long long *x, long long*y) {
    if(b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    long long x1, y1;
    int g = GCD(b, a%b, &x1, &y1);

    *x = y1;
    *y = x1 - (a/b)*y1;
    return g;
}

int main() {
    long long a, b, c, x, y;
    scanf(" %d %d %d", &a, &b, &c);
    long long gcd = GCD(a,b, &x, &y);
    if(c%gcd!=0) {
        printf("-1\n");
        return 0;
    }

    a /= gcd;
    b /= gcd;
    c /= gcd;

    x *= -c;
    y *= -c;

    if((x > 5e18 || x < -5e18) && x + absl(b) > 5e18 && (y > 5e18 || y < -5e18) && y - absl(a) < -5e18) {
        printf("-1\n");
        return 0;
    }

    printf("%lld %lld\n", x, y);
    return 0;
}