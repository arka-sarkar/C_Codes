#include <stdio.h>

int main(int argc, char *argv[])
{
    char str[100];
    int i = 0, j = 0;
    scanf("%s", str);
    while (str[i] != '\0')
    {
        if (i == 0 || str[i] != str[i - 1])
        {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
    printf("%s\n", str);

    return 0;
}