#include<stdio.h>
#define COLS 3

int row_magnitude_sq(const int *r, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += *(r+i)**(r+i);
    return sum;
}

void sort_rows_by_magnitude(int *row_ptrs[], int n, int cols) {
    int min;

    for (int i = 0; i < n-1; i++) { // selection sort
        min = i;
        for (int j = i+1; j < n; j++) {
            if(row_magnitude_sq(row_ptrs[j], COLS)<row_magnitude_sq(row_ptrs[min], COLS)) min = j;
        }
        if(min != i) {
            int *temp = row_ptrs[i];
            row_ptrs[i] = row_ptrs[min];
            row_ptrs[min] = temp;
        }
    }
}

int main() {
    int matrix[20][COLS], n, *row_ptrs[20];
    
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        row_ptrs[i] = matrix[i];
        for (int j = 0; j < COLS; j++) scanf(" %d", matrix[i]+j);
    }
    
    sort_rows_by_magnitude(row_ptrs, n, COLS);
    for (int i = 0; i < n; i++) {
        printf("[Original Row %td] ", (row_ptrs[i]-matrix[0])/COLS);
        for (int j = 0; j < COLS; j++) {
            if(j != 0) putchar(' ');
            printf("%d", row_ptrs[i][j]);
        }
        putchar('\n');
    }
    
    printf("Original Matrix:\n");
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < COLS; j++) {
            if(j != 0) putchar(' ');
            printf("%d", matrix[i][j]);
        }
        putchar('\n');
    }
    return 0;
}