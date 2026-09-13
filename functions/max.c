#include<stdio.h>

int max(int a, int b){
    if(a>b) return a;
    return b;
}

int main(int argc, char* argv[]) {
    int a,b;
    scanf("%d %d", &a, &b);
    printf("%d\n", max(a,b));
    return 0;
}