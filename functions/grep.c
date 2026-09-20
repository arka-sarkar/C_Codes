#include<stdio.h>
#include<string.h>
#define MAX 100

int read_line(char line[], int max) {
    int length=0;
    char c = getchar();
    for(;length<max-1 && c != EOF && c!='\n'; length++) {
        line[length] = c;
        c = getchar();
    }

    line[length] = '\0';
    return length;
}

int strindex(char s[], char t[]) {
    int i=0, j, k;

    for (; s[i]; i++) {
        for(j=i, k=0; t[k] && s[j]==t[k]; j++, k++);
        if(k>0 && !t[k]) return i;
    }
    return -1;
}

int main(int argc, char const *argv[]) {
    char line[MAX];
    
    return 0;
}
