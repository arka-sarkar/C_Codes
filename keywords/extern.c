#include<stdio.h>
extern int count;
extern void increment(void);
// void increment() {
//     count++;
// }

/*
    /usr/bin/ld: /tmp/ccTDjrep.o: in function `increment':
    extern.c:(.text+0x0): multiple definition of `increment'; /tmp/ccYtesrA.o:reference.c:(.text+0x0): first defined here
    collect2: error: ld returned 1 exit status
*/

int main() {
    increment();
    printf("%d\n", count);
    return 0;
}