#include<stdio.h>
#include<stdlib.h>

int **alloc_matrix(int m, int n) {
    int **M = calloc(m, sizeof(int*));
    if(M==NULL) exit(1);

    for (int i = 0; i < m; i++) {
        M[i] = calloc(n, sizeof(int));
        if(M[i] == NULL) {
            for (int j = 0; j < i; j++) free(M[j]);
            free(M);
            exit(1);
        }
    }
    return M;
}

void input_matrix(int** mat, int row, int col) {
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++) scanf(" %d", &mat[i][j]);
}

int** matrix_mul(int** mat1, int** mat2, int m, int n, int p) {
    int** res = alloc_matrix(m, p);
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) sum += mat1[i][k]*mat2[k][j];
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

void free_matrix(double** matrix, int m) {
    for (int i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int **mat1, **mat2, **res;
    int m, n;
    printf("Enter the size of first matrix (<row>x<col>): ");
    scanf(" %dx%d", &m, &n);

    int n1, p;
    printf("Enter the size of second matrix: ");
    scanf(" %dx%d", &n1, &p);

    if(n!=n1) {
        fprintf(stderr, "The no. of columns in first matrix must be equal to no. of rows in second matrix.\n");
        exit(1);
    }

    mat1 = alloc_matrix(m, n);
    mat2 = alloc_matrix(n, p);

    printf("\nEnter the elements of first matrix:\n");
    input_matrix(mat1, m, n);

    printf("\nEnter the elements of second matrix:\n");
    input_matrix(mat2, m, n);
    
    res = matrix_mul(mat1, mat2, m, n, p);
    putchar('\n');
    display_matrix(res, m, p);
    free_matrix(mat1, m);
    free_matrix(mat2, n);
    free_matrix(res, m);
    putchar('\n');
    return 0;
}