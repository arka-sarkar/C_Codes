#include<stdio.h>
#include"reverse.h"

int isPalindrome(int num) {
    if(num == reverse(num)) return 1;
    else return 0;
}