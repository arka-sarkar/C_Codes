#include<stdio.h>
#include<string.h>

void gen(char *src, int n, char *buf, int used[], int pos) {
    if(pos == n) {
        buf[n] = '\0';
        puts(buf);
        return;
    }

    for (int i = 0; i < n; i++) {
        if(used[i]) continue;
        if(i>0 && src[i]==src[i-1] && !used[i-1]) continue;
        used[i] = 1;
        buf[pos] = src[i];
        gen(src, n, buf, used, pos+1);
        used[i] = 0;
    }
}

void permute(char *s, int l, int r) {
    int n = r-l+1;
    char src[n+1], buf[n+1];
    int used[n];

    memcpy(src, s+l, n);
    src[n] = '\0';

    for (int i = 1; i < n; i++) { // Insertion sort on char array so something like "cab" becomes "abc"
        char key = src[i];
        int j = i-1;
        while(j >= 0 && src[j] > key) { src[j+1] = src[j]; j--; }

        src[j+1] = key;
    }
    
    memset(used, 0, sizeof used);
    gen(src, n, buf, used, 0);
}

int main() {
    char s[31];
    scanf(" %30[^\n]", s);
    permute(s, 0, strlen(s)-1);
    return 0;
}
