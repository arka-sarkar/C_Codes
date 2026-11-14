#include<stdio.h>
#include<string.h>

int isPalin(char s[], int left, int right) {
    if(left >= right) return 1;
    if(s[left] != s[right]) return 0;

    return isPalin(s, left+1, right-1);
}

int main() {
    char s[101];
    scanf("%100s", s);
    char* message = isPalin(s, 0, strlen(s)-1)?"YES":"NO";
    printf("%s\n", message);
    return 0;
}