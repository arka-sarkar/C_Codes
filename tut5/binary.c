#include<stdio.h>
#include<math.h>

unsigned long long binary(unsigned int num) {
    unsigned long long bin = 0;
    int count = 0;
    while(num > 0) {
        bin +=(unsigned long long) (num%2)*powl(10, count);
        num /= 2;
        count++;
    }
    return bin;
}

int main(int argc, char* argv[]) {
    unsigned int num;
    printf("Binary form: %llu\n", binary(num));
    return 0;
}