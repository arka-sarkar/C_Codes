#include<stdio.h>

int main(int argc, char* argv[]) {
    char input[100];
    fgets(input, 100, stdin);
    printf("%s\n", input);
    return 0;
}