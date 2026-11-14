#include<stdio.h>
#include<stdbool.h>

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

int extractCore(int num) {
    int result = -1;
    short digits = no_of_digit(num);
    if(digits == 2) result = 0;
    else if(digits >= 3 && digits <= 5) {
        num /= 10;
        num %= power(10, digits-2);
        result = num;
    }
    return result;
}

bool isStrong(int num) {
    int sum=0;
    while(num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum % 2 == 0 && sum > 0;
}

int main() {
    int p1, p2, gold;
    scanf(" %d %d", &p1, &p2);
    int core1 = extractCore(p1), core2 = extractCore(p2);

    if(core1 == -1 || core2 == -1) {
        printf("Both numbers should be from 10 to 99999.\n");
        return 1;
    } else {
        if(isStrong(core1) && isStrong(core2)) gold = core1 * core2;
        else if(isStrong(core1) || isStrong(core2)) gold = core1 + core2;
        else gold = 0;
        printf("%d\n", gold);
    }
    return 0;
}