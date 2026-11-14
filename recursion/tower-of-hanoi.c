#include<stdio.h>

// void hanoi(int A[], int B[], int C[], int n) {
//     if(n == 0) return;
//     hanoi(A, C, B, n-1);
//     C[0] = A[n-1];
//     hanoi(B, A, C, n-1);
// }
void hanoi(int n, char source, char dest, char aux) {
    if(n == 0) return;
    hanoi(n-1, source, aux, dest);
    printf("Move disk %d: %c -> %c\n", n, source, dest);
    hanoi(n-1, aux, dest, source);
}

int main() {
    hanoi(3, 'A', 'C', 'B');
    return 0;
}