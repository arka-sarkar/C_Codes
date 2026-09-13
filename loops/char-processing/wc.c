#include<stdio.h>
#include<ctype.h>

int main(int argc, char* argv[]) {
    char c,p='\t';
    int n=0;
    while ((c=getchar())!=EOF)
    {
        if(!isspace(c) && isspace(p)) ++n;
        p = c;
    }
    printf("\nWord count: %d\n", n);
    return 0;
}