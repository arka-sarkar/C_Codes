#include<stdio.h>

int main(int argc, char *argv[]) {
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }
    FILE *fp = fopen(argv[1], "rb");
    if(fp == NULL) {
        perror(argv[1]);
        return 1;
    }
    int c;
    while((c=fgetc(fp))!=EOF) putchar(c);
    putchar('\n');
    fclose(fp);
    return 0;
}
