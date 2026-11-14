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

// Gives kth digit from start
int kthDigit(int num, int k) {
    int digits = no_of_digit(num);
    return (num % power(10,digits-k+1))/power(10, digits-k);
}

// Sorting through selection sort
int sortDigitsDescending(int num) {
    int result = num, max;
    int digits = no_of_digit(num), source, dest;
    for (int i = 1; i <= digits; i++) {
        max = i;
        for(int j = i+1; j <= digits; j++) {
            if(kthDigit(result, j) > kthDigit(result, max)) max = j; 
        }

        // Swapping digits
        source = kthDigit(result, i);
        dest = kthDigit(result, max);
        result +=  (dest-source)*(power(10, digits-i)-power(10, digits-max));
    }
    return result;
}

int main() {
    int num;
    scanf(" %d", &num);

    int result = sortDigitsDescending(num);
    printf("%d\n", result);
    return 0;
}