#include<stdio.h>
static int x=10;

void fun() {
    int x=20;
    x=30; // Not keeping int x=20 leads to 30 being put in static int x
    printf("Inside fun: %d\n", x);
}

int main() {
    fun();
    printf("Inside main: %d\n", x);
    return 0;
}