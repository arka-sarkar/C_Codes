#include<stdio.h>

int main(int argc, char* argv[]) {
    int i = 1;
    {int i = 2;printf("%d\n",i);}
    printf("%d\n", i);
    return 0;
}