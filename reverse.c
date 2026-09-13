#include<stdio.h>
#include<math.h>

int main() {
    unsigned long num, rev_num=0;
    printf("Enter a number: ");

    if(scanf("%lu",&num)!=1) return 1;
    
    // unsigned short digit = (unsigned short)log10(num) + 1;
    // unsigned short quo;
    // for (int i = digit-1; i >= 0; i--) {
    //     quo = (unsigned short)(num/pow(10, i));
    //     num %= (unsigned long)pow(10, i);
    //     rev_num += quo*(unsigned long)pow(10, digit-i-1);
    // }

    while (num>0) {
        rev_num = rev_num*10 + num%10;
        num /= 10;
    }
    
    printf("The reversed number is %lu\n", rev_num);
    return 0;
}
