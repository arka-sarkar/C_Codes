#include<stdio.h>

int no_of_digit(int num) {
    int digits = 0;
    while(num != 0) {
        digits++;
        num /= 10;
    }
    return digits;
}

int power(int base, int exp) {
    int result = 1;
    for(int i = 0; i < exp; i++) result *= base;
    return result;
}

int kthDigit(int num, int k) {
    int digits = no_of_digit(num);
    return (num % power(10,digits-k+1))/power(10, digits-k);
}

int isPalindrome(int num) {
    int digits = no_of_digit(num);
    int isPalin = 1;
    for (int i = 1; i <= (digits/2); i++) {
        if(kthDigit(num, i) != kthDigit(num, digits-i+1)) {
            isPalin = 0;
            break;
        }
    }
    return isPalin;
}

int main(int argc, char* argv[]) {
    int num;
    scanf("%d", &num);
    printf("%s\n", isPalindrome(num)?"Palindrome":"Not palindrome");
    return 0;
}