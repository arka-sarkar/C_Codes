#include<stdio.h>
#include<string.h>

int main(int argc, char* argv[]) {
    char str1[] = "abc";
    char str2[] = "abc";
    if(!strncmp(str1, str2, 3)) printf("True\n");
    else printf("False\n");
    return 0;
}