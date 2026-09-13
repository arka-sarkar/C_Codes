#include<stdio.h>

int main(int argc, char* argv[]) {
    int count=0;
    char c=getchar();
    while ((c=getchar())!=EOF)
    {
        count++;
    }
    printf("\n%d\n",count);
    return 0;
}