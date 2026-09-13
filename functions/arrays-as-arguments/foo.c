#include<stdio.h>

void foo(int arr[]) {
    printf("%p\n",arr);
}

int main(int argc, char* argv[]) {
    int a[]={10,20,30,40,50};
    foo(a);
    return 0;
}