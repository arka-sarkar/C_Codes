#include <stdio.h>
#include <ctype.h>

int main() {
    int is_valid;
    char c;
    while ((c = getchar()) != EOF) {
        if (!isalnum(c)) {
            continue;
        }
        is_valid = 1;
        while (c != EOF && isalnum(c)) {
            if (isdigit(c)) is_valid = 0;            
            if (is_valid) putchar(c);           
            c = getchar();
        }

        if (!isalnum(c)) putchar('\n');
    }
    putchar('\n');
    return 0;
}