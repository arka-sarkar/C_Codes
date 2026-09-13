#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100

char* longest_seq(char* str) {
    char c;
    int length = strlen(str);
    int currlength=0, maxlength=0, index;
    if(length != 1){
        for(int i = 0; i < length-1; i++) {
            if(str[i] == str[i+1]) {
                currlength++;
            } else {
                currlength++;
                if(currlength > maxlength) {
                    index = i;
                    c = str[i];
                    maxlength = currlength;
                    currlength = 0;
                } else if(currlength == maxlength) {
                    c = str[index];
                    break;
                }
            }
        }
        if(str[length-1] == str[length-2]) {
            currlength++;
            if(currlength > maxlength) {
                c = str[length-1];
                maxlength = currlength;
            } else if(currlength == maxlength) {
                c = str[index];
            }
        }
    } else {
        c = str[0];
        maxlength = 1;
    }
    char* output = calloc(MAX, sizeof(char));
    snprintf(output, sizeof(output), "%c %d", c, maxlength);
    return output;
}

int main(int argc, char* argv[]) {
    char input[MAX];
    scanf(" %[^\n]", input);
    printf("%s\n",longest_seq(input));
    return 0;
}