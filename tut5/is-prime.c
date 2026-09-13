#include<stdio.h>
#include<stdbool.h>
#include<math.h>

bool isPrime(int n) {
    for (int i = 2; i <= sqrtf(n); i++) {
        if(n%i == 0) return false;
    }
    return true;
}

int main(int argc, char* argv[]) {
    int n;
    scanf("%d",&n);

    if(isPrime(n)) printf("%d is prime.\n", n);
    else printf("%d is not prime.\n", n);
    return 0;
}