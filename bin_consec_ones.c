#include<stdio.h>

unsigned int consecOnes(unsigned int num) {
    unsigned int countPrev, count=0 , countFinal=0;

    while(num!=0) {
        if((num & 1u) == 1) count++; // Checks whether the last bit of num from start in each iteration is 1.
        else {
            countPrev = count;
            count = 0;
            if(countFinal < countPrev) countFinal = countPrev;
        }
        num >>= 1; // Shifts the bits of num by one step right. (dividing by 2)
    }

    if(count > countFinal) countFinal = count; // This is for cases like 1111100111001.(first countFinal =1, then 3 but without this line the value 5 from 5 contiguous 1's won't be put into countFinal.)
    return countFinal;
}

int main() {
    unsigned int num;
    scanf("%u",&num);
    printf("%u\n", consecOnes(num));
    return 0;
}