#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char str[100];
    int i, n = 0, palindrome = 1;
    fgets(str, 100, stdin);

    for (int i = 0; i < strlen(str) / 2; i++)
    {
        if (str[i] != str[strlen(str) - i - 2])
        {
            palindrome = 0;
            break;
        }
    }

    if (palindrome)
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");
    return 0;
}