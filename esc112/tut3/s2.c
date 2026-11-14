#include<stdio.h>
#define CHANNELS 4

void row_min_max(const int* row, int n, int* min_val, int* max_val) {
    *min_val = *max_val = row[0];
    int *p = row;
    for (int i = 1; i < n; i++, p++) {
        if(*p < *min_val) *min_val = *p;
        if(*p > *max_val) *max_val = *p;
    }
}

void scale_row(int *row, int n, int factor) {
    int *p = row;
    for (int i = 0; i < n; i++, p++) (*p) *= factor;
}

int column_max(int data[][CHANNELS], int n, int col) {
    int max = data[0][col];
    for (int i = 1; i < n; i++) {
        if(data[i][col] > max) max = data[i][col];
    }
    return max;
}

int main() {
    int n;
    scanf(" %d", &n);

    int data[n][CHANNELS], max_val, min_val;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < CHANNELS; j++) scanf(" %d", &data[i][j]);
    
    for (int i = 0; i < n; i++) {
        row_min_max(data[i], CHANNELS, &min_val, &max_val);
        printf("Row %d: min=%d max=%d\n", i, min_val, max_val);

        if(max_val - min_val > 20) scale_row(data[i], CHANNELS, 2);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < CHANNELS; j++) {
            if(j != 0) putchar(' ');
            printf("%d", data[i][j]);
        }
        putchar('\n');
    }
    
    for (int i = 0; i < CHANNELS; i++) {
        if(i != 0) putchar(' ');
        printf("%d", column_max(data, n, i));
    }
    
    putchar('\n');
    return 0;
}