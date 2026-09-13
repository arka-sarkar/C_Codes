#include<stdio.h>

int main(int argc, char const *argv[])
{
    char c;
    int ret = scanf("%c",&c);
    printf("\nret = %d, c = %d\n", ret, (unsigned short)c);
    if (c >= 'A' && c <= 'Z') printf("Upper\n");
    else if (c >= 'a' && c <= 'z') printf("Lower\n");
    else printf("Non-alphabetic\n");
    
    return 0;
}
