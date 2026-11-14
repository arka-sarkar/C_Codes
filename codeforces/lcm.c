#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int GCD(int a, int b) {
    if(a < b) GCD(b, a);
    int rem;
    do {
        rem = a % b;
        a = b;
        b = rem;
    } while(rem!=0);
    return a;
}

bool isGood(int size, int a[]) {
    bool good = true;
    for (int i = 0; i <= size-2; i++) {
        if(a[0] != 1 && GCD(a[i+1], a[i])!=a[i+1]-a[i]) {
            good = false;
            break;
        }
    }
    return good;
}

void rec(int k, int n, int m, int no_zero, int a[], int zero[], unsigned long long* count) {
    if(k == no_zero) {
        if(isGood(n, a)) (*count)++;
        return;
    }
    
    for(int i = 2; i <= m; i++) {
        a[zero[k]] = i;
        rec(k+1, n, m, no_zero, a, zero, count);
    }
    a[zero[k]] = 0;
}

int main() {
	int test_cases;
	scanf("%d", &test_cases);
	int n[test_cases], m[test_cases];
	unsigned long long count[test_cases];
	int *a[test_cases];
	int no_zero[test_cases], *zero_pos[test_cases];
	for (int i = 0; i < test_cases; i++) {
	    no_zero[i] = 0;
	    scanf(" %d %d", &n[i], &m[i]);
		a[i] = calloc(n[i], sizeof(int));
		for (int j = 0; j < n[i]; j++) {
		    scanf(" %d", &a[i][j]);
			if(!a[i][j]) no_zero[i]++;
		}

		zero_pos[i] = calloc(no_zero[i], sizeof(int));

		for (int j = 0, k = 0; j < n[i]; j++) {
		    if(!a[i][j]) zero_pos[i][k++] = j;
		}
	}

	for (int i = 0; i < test_cases; i++) {
	    count[i] = 0;
	    rec(0, n[i], m[i], no_zero[i], a[i], zero_pos[i], &count[i]);
		printf("%llu\n", count[i]%998244353);
	}
	return 0;
}