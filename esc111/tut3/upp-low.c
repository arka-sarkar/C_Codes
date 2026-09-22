#include<stdio.h>
#include<ctype.h>

int main(int argc, char* argv[]) {
    char c;
    while ((c=getchar())!=EOF)
    {
        if(isupper(c)) putchar(tolower(c));
        else if(islower(c)) putchar(toupper(c));
        else putchar(c);
    }
    putchar('\n');
    return 0;
}