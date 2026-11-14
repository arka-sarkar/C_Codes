#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<readline/readline.h>

void trim(char str[]) {
    int length=strlen(str);
    int last;
    for(last = length-1; isspace(str[last]); last--);
    str[last+1] = '\0'; // Removes trailing spaces, last finds of the index of last non-whitespace character.

    int first;
    for(first = 0; isspace(str[first]); first++); // first finds the index of first non-whitespace character.

    for(int j = 0; j <= last-first+1; j++) str[j] = str[first+j]; // Shifts the remaining section to start.
}

int main() {
    char* input = readline("Enter a string: "); // used readline instead of scanf or fgets or getchar to get 
                                  // ability to move cursor while giving input or else
                                  // we'll get ^]]D or ^]]C while using left or right arrow keys respectively.
    trim(input);
    printf("%s\n", input);
    free(input);
    return 0;
}