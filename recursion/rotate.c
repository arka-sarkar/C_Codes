#include<stdio.h>
#include<string.h>

void shiftLeft(char *s) {
    s[0] = s[1];
    if(strlen(s) == 0) return;
    shiftLeft(s+1);
}

void rotateLeft(char *s, int n) {
    if(n == 0) return;
    int length = strlen(s);
    char c = s[0];
    shiftLeft(s);
    s[length-1] = c;
    rotateLeft(s, n-1);
}

int main() {
    char word[101];
    int n;
    scanf(" %s %d", word, &n);
    rotateLeft(word, n);
    printf("%s\n", word);
    return 0;
}