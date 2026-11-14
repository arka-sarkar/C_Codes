#include<stdio.h>
#include<stdlib.h>

int alloc_matrix(int*** M, int m, int n) {
    *M = calloc(m, sizeof(int*));
    if(*M==NULL) return 0;

    for (int i = 0; i < m; i++) {
        (*M)[i] = calloc(n, sizeof(int));
        if((*M)[i] == NULL) {
            for (int j = 0; j < i; j++) free((*M)[j]);
            free(*M);
            return 0;
        }
    }
    return 1;
}

void input_matrix(int** mat, int row, int col) {
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++) scanf(" %d", &mat[i][j]);
}

int** transpose(int **matrix, int row, int col) {
    int **trn;
    if(!alloc_matrix(&trn, col, row)) exit(1);
    for(int i = 0; i < col; i++)
        for(int j = 0; j < row; j++) trn[i][j] = matrix[j][i];
    
    return trn;
}

int** matrix_mul(int** mat1, int r1, int c1, int** mat2, int r2, int c2) {
    if(c1 != r2) {
        fprintf(stderr, "The no. of columns in first matrix must be equal to no. of rows in second matrix.\n");
        exit(1);
    }

    int** res; 
    if(!alloc_matrix(&res, r1, c2)) exit(1);
    
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            int sum = 0;
            for (int k = 0; k < c1; k++) sum += mat1[i][k]*mat2[k][j];
            res[i][j] = sum;
        }
    }
    return res;
}

void display_matrix(int** mat, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if(j != 0) putchar(' ');
            printf("%d", mat[i][j]);
        }
        if(i != row-1) putchar('\n');
    }
}

void free_matrix(int** matrix, int m) {
    for (int i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int row, col;
    scanf(" %d %d", &row, &col);

    int **matrix;
    if(!alloc_matrix(&matrix, row, col)) exit(1);

    input_matrix(matrix, row, col);

    int **trn = transpose(matrix, row, col);

    printf("Transpose:\n");
    display_matrix(trn, col, row);
    int **prod = matrix_mul(matrix, row, col, trn, col, row);
    printf("\nProduct (A * A^T):\n");
    display_matrix(prod, row, row);
    putchar('\n');
    free_matrix(matrix, row);
    free_matrix(trn, col);
    free_matrix(prod, row);
    return 0;
}