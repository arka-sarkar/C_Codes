#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void build(char *buf, char** ans, int pos, int open, int close, int n, int *returnSize) {
    if(pos == 2*n) {
        buf[pos] = '\0';
        ans[*returnSize]=malloc(2*n+1);
        strcpy(ans[(*returnSize)++], buf);
        return;
    }

    if(open<n) {
        buf[pos]='(';
        build(buf, ans, pos+1, open+1, close, n, returnSize);
    }
    if(open>close) {
        buf[pos]=')';
        build(buf, ans, pos+1, open, close+1, n, returnSize);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    *returnSize = 0;
    char *buf=malloc(2*n+1);
    char **ans=malloc(9694845*sizeof(char*));
    build(buf, ans, 0, 0, 0, n, returnSize);
    free(buf);
    ans = realloc(ans, (*returnSize)*sizeof(char*));
    return ans;
}

int main() {
    int returnSize, n;  
    scanf(" %d", &n);
    char **ans = generateParenthesis(n, &returnSize);
    //printf("%d\n", returnSize);
    for(int i=0; i<returnSize; i++) {
        printf("%s\n", ans[i]);
        free(ans[i]);
    }
    free(ans);
    return 0;
}