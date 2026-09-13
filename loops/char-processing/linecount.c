#include<stdio.h>

int main(int argc, char* argv[]) {
    char c;
    int line_count;
    while ((c=getchar())!=EOF) if(c=='\n') line_count++;
    printf("\nNo of lines: %d\n", line_count);
    return 0;
}