#include<stdio.h>
#include<stdlib.h>

unsigned long long max(unsigned long long a, unsigned long long b) {
    return (a>b)?a:b;
}

int main() {
	unsigned long long s, x;
	scanf("%llu %llu", &s, &x);
	unsigned long long count = 1, copy_x = x;
	if((s-x)%2!=0) {
	    printf("0\n");
	    exit(0);
	}
	unsigned long long a = (s-x)/2;
	while (max(a, x) != 0) {
	    if((x&1u) == 1){ 
			if((a&1u) == 0) count*=2;
			else {
			    count = 0;
				break;
			}
		}
		
	    x>>=1u;
		a>>=1u;
	}
	if(s==copy_x) count-=2;
	printf("%llu\n", count);
	return 0;
}