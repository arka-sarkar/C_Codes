#include<stdio.h>

int strcmp(char* str1, char* str2) {
    int i;
    for(i = 0; str1[i] == str2[i]; i++)
        if(str1[i] == '\0' || str2[i] == '\0')
            return 0;
    return str1[i] - str2[i];
}

int main() {
    char s1[] = "wax";
    char s2[] = "was";
    printf("%d\n", strcmp(s1, s2));
    return 0;
}