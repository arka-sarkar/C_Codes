#include<stdio.h>
#include<stdlib.h>

int **alloc_jagged(int m, const int *sizes) {
    int **M = calloc(m, sizeof(int*));
    if(M == NULL) {
        fprintf(stderr, "Allocation failed.\n");
        exit(1);
    }
    
    for (int i = 0; i < m; i++) {
        M[i] = calloc(sizes[i], sizeof(int));
        if(M[i] == NULL) {
            for (int j = 0; j < i; j++) free(M[j]);
            free(M);
            fprintf(stderr, "Allocation failed.\n");
            exit(1);
        }
    }
    return M;
}

void free_jagged(int **arr, int m){
    for (int i = 0; i < m; i++) free(arr[i]);
    free(arr);
}

void committee_stats(const int *row, int n, int *sum, double *avg) {
    *sum = 0;
    for (int i = 0; i < n; i++) *sum += row[i];

    *avg = (double)(*sum)/n;
}

void find_top_contributor(int **arr, const int *sizes, int m, int *best_hours, int *best_committee, int *best_member) {
    *best_hours = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            if(arr[i][j] > *best_hours) {
                *best_hours = arr[i][j];
                *best_committee = i;
                *best_member = j;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int* sizes = calloc(n, sizeof(int));
    
    for (int i = 0; i < n; i++) scanf(" %d", sizes+i);
    int** hours = alloc_jagged(n, sizes);

    for (int i = 0; i < n; i++) {
        for(int j = 0; j < sizes[i]; j++) scanf(" %d", hours[i]+j);
    }
    
    int sum, best_hours, best_commitee, best_memeber;
    double avg;

    for (int i = 0; i < n; i++) {
        committee_stats(hours[i], sizes[i], &sum, &avg);
        printf("Commitee %d: Total = %d, Average = %.2f\n", i, sum, avg);
    }
    find_top_contributor(hours, sizes, n, &best_hours, &best_commitee, &best_memeber);
    if(best_hours != 1)
        printf("Top Contributor: %d hours (Commitee %d, Member %d)\n", best_hours, best_commitee, best_memeber);
    else
        printf("Top Contributor: %d hour (Commitee %d, Member %d)\n", best_hours, best_commitee, best_memeber);

    free_jagged(hours, n);
    free(sizes);
    return 0;
}