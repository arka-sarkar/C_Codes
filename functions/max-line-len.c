#include<stdio.h>
#define MAX 101

int read_line(char[], int);
void copy_line(char[], char[]);

int main(int argc, char* argv[]) {
    char line[MAX], maxline[MAX];
    int len, maxlen=0;
    while (len=read_line(line,MAX))
    {
        if(len>maxlen) {
            maxlen = len;
            copy_line(line, maxline);
        }
    }
    
    printf("%d %s\n", maxlen, maxline);
    return 0;
}

int read_line(char line[], int max) {
    int length=0;
    char c;
    for(;length<max-1 && (c=getchar()) != EOF && c!='\n'; length++) line[length] = c;

    line[length] = '\0';
    return length;
}

void copy_line(char src[], char dest[]) {
    int length = 0;
    for (;src[length]; length++) dest[length] = src[length];
    src[length] = '\0';
}