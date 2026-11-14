#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int n = matrixSize;
    for(int i=0; i<=n-2; i++) {
        for(int j=i+1; j<=matrixColSize[i]-1; j++) {
            swap(&matrix[i][j], &matrix[j][i]);
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<matrixColSize[i]/2; j++) {
            swap(&matrix[i][j], &matrix[i][n-j-1]);
        }
    }
}

int main() {
    int n;
    scanf(" %d", &n);
    int **matrix = calloc(n, sizeof(int*));
    int matrixColSize[n];
    for(int i=0; i<n; i++) {
        matrixColSize[i]=n;
        matrix[i] = calloc(n, sizeof(int));
        for(int j=0; j<n; j++) scanf(" %d", matrix[i]+j);
    }
    rotate(matrix, n, matrixColSize);
    printf("Rotated Matrix (Clockwise):\n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(j != 0) putchar(' ');
            printf("%d", matrix[i][j]);
        }
        free(matrix[i]);
        putchar('\n');
    }
    free(matrix);
    return 0;
}