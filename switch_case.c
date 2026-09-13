#include<stdio.h>

typedef char* string;

int main(int argc, char const *argv[])
{
    int x = 1;
    string num;

    switch (x)
    {
    case 1:
        num = "one";
        break;
    
    case 2:
        num = "two";
        break;

    default:
        num = "three";
        break;
    }

    printf("%s\n", num);

    return 0;
}