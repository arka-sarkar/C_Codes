#include<stdio.h>

int sum(int a, int b) {return a+b;}

void greetHelloAndExecute(int (*fPtr)(int , int)) {
    printf("Hello user.\n");
    printf("The sum of the numbers 5 anf 7 is %d.\n", (*fPtr)(5, 7));
}

void greetGmAndExecute(int (*fPtr)(int, int)) {
    printf("Good morning user.\n");
    printf("The sum of 5 and 7 is %d.\n", (*fPtr)(5, 7));
}

int main() {
    greetHelloAndExecute(&sum);
    putchar('\n');
    greetGmAndExecute(&sum);
    return 0;
}