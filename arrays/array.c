#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]) {
    int* a=calloc(5,sizeof(int));
    for (int i = 0; i < 5; i++) scanf(" %d",a+i);
    for (int i = 0; i < 5; i++) {if(i) printf(" "); printf("%p",(a+i));}
    putchar('\n');
    for (int i = 0; i < 5; i++) {if(i) printf(" "); printf("%d",*(a+i));}
    putchar('\n');
    free(a);
    a=NULL;
    return 0;
}