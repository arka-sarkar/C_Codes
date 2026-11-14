#include<stdio.h>
#include<math.h>

int main() {
	unsigned long long m, n, k;
	scanf(" %llu %llu %llu", &m, &n, &k);
	unsigned long long squares = ceil((double)m/k)*ceil((double)n/k);
	printf("%llu\n", squares);
	return 0;
}