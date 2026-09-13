#include<stdio.h>
#include<ctype.h>

int main(int argc, char* argv[]) {
    char c;
    int wc;
    while ((c=getchar()) != EOF) if(isalnum(c)) wc++;
    printf("\nLetter Count: %d\n", wc);
    return 0;
}