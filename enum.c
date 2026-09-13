#include<stdio.h>

enum escaped { BELL = '\a', BACKSPACE = '\b', TAB = '\t', NEWLINE = '\n'};
enum months {JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};

int main(int argc, char* argv[]) {
    enum months m1 = 0, m2 = JAN;

    printf("%d %d\n", m1, m2);
    return 0;
}