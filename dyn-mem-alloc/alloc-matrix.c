#include<stdio.h>
#include<stdlib.h>

double **alloc_matrix(int m, int n) {
    double **M = calloc(m, sizeof(double*));
    if(M==NULL) exit(1);

    for (int i = 0; i < m; i++) {
        M[i] = calloc(n, sizeof(double));
        if(M[i] == NULL) {
            for (int j = 0; j < i; j++) free(M[j]);
            free(M);
            exit(1);
        }
    }
    return M;
}

void free_matrix(double** matrix, int m) {
    for (int i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	double** matrix = alloc_matrix(m, n);
	for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %lf", &matrix[i][j]);
        }
	}
	for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", matrix[i][j]);
        }
        putchar('\n');
	}
	free_matrix(matrix, m);
	return 0;
}