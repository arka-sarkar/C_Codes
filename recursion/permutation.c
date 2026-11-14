#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int factorial(int n, int acc) {
    if(n == 1 || n == 0) return acc;
    return factorial(n-1, acc*n);
}

void getPerms(int *nums, int **ans, int numSize, int index, int* count) {
    if(index == numSize) {
        memcpy(ans[*count], nums, numSize*sizeof(int));
        (*count)++;
        return;
    }

    for(int i = index; i < numSize; i++) {
        swap(nums+index, nums+i);
        getPerm(nums, ans, numSize, index+1, count);
        swap(nums+index, nums+i);
    }
}

int** permute(int *nums, int numSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = factorial(numSize, 1);
    *returnColumnSizes = calloc(*returnSize, sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = numSize;
    }
    
    int **ans = malloc((*returnSize)*sizeof(int*));
    for(int i = 0; i < *returnSize; i++) ans[i] = malloc((*returnColumnSizes)[i]*sizeof(int));

    int count = 0;
    getPerms(nums, ans, numSize, 0, &count);
    return ans;
} 

int main() {
    int nums[] = {1, 2, 3};
    int returnSize, *returnColumnSizes;
    int **ans = permute(nums, 3,  &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; i++) {
        for(int j = 0; j < returnColumnSizes[i]; j++) {
            if(j != 0) putchar(' ');
            printf("%d", ans[i][j]);
        }
        putchar('\n');
    }
    
    return 0;
}