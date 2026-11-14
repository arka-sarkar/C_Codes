#include<stdio.h>

void recurse(int n) {
    static int depth=0;
    depth++;
    printf("n=%d depth=%d\n", n, depth);
    if(n>0) recurse(n-1);
    depth--;
}

int main() {
    recurse(3);
    return 0;
}