#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

void binary(int n, int *returnSize, char *out) {
    if(n == 0) return;
    binary(n/2, returnSize, out);
    out[(*returnSize)++]=(n%2)+'0';
}

bool queryString(char* s, int n) {
    bool res = true;
    char *out = malloc((int)log2(n)+2);
    int returnSize;
    for(int i=1; i<=n; i++) {
        returnSize=0;
        binary(i, &returnSize, out);
        out[returnSize++]='\0';
        char *ptr = strstr(s, out);
        if(ptr == NULL) {
            res = false;
            break;
        }
    }
    free(out);
    return res;
}

int main() {
    char s[1001];
    int n;
    scanf(" %1000s %d", s, &n);
    bool out = queryString(s, n);
    char *message = (out==true)?"true":"false";
    printf("%s\n", message);
    return 0;
}