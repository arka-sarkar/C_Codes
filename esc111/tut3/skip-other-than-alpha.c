#include<stdio.h>
#include<ctype.h>

int main(int argc, char* argv[]) {
    char c, prev;
    prev = 'a';
    while ((c=getchar())!=EOF)
    {   
        if(isalpha(prev)){ 
            if(!isalpha(c)) putchar('\n');
            else putchar(c);
        } else {
            if(isalpha(c)) putchar(c);
        }
        prev = c;
    }
    putchar('\n');
    return 0;
}