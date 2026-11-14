#include<stdio.h>

int abs(int num) { return num>0?num:(-num); }

int isPrime(int num) {
    int isPrime=1;
    for(int i=2; i<=num/2 ;i++) {
        if(num%i==0) {
            isPrime = 0;
            break;
        }
    }
    return isPrime;
}

int getLPD(int num) {
    int factor;
    for(factor=num-1; num%factor ; factor--) ;
    return factor;
}

int main(int argc, char* argv[]) {
    int c1, c2;
    scanf("%d %d", &c1, &c2);

    if(c1 < 10 || c2 < 10 || c1 > 99999 || c2 > 99999) {
        printf("Please input numbers from 10 to 99999.\n");
        return 1;
    }

    int lpd1 = getLPD(c1), lpd2 = getLPD(c2);
    int festival_num;
    if(isPrime(lpd1) && isPrime(lpd2)) festival_num = lpd1 + lpd2;
    else if(isPrime(lpd1) || isPrime(lpd2)) festival_num = c1 * c2;
    else festival_num = abs(lpd1-lpd2);

    printf("%d\n", festival_num);
    return 0;
}