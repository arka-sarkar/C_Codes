#include<stdio.h>
#include<stdint.h>

int main() {
    uint64_t n;
    scanf(" %lu", &n);

    int count=0;

    // Brute-force method
    // while (n != 0) {
    //     count += (n & 1u); // n%2
    //     n >>= 1; // n/=2
    // }
    // This loop runs as many times as the length of the binary representation of the number. (leftmost 1 to rightmost bit)

    // Brian Kernighan's bit-clearing loop(more efficient)
    while(n != 0) {
        n &= n-1; // Sets the rightmost 1 to 0
        count++;
    }
    // The loop runs as many times as the number of 1's in the binary representation of the number.

    printf("%d\n", count);
    return 0;
}