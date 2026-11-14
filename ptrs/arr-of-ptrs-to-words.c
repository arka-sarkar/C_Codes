#include<stdio.h>

int main() {
    char sentence[] = "C pointers are useful";
    char *words[4];
    char *p = sentence;
    int count = 0;

    while (*p) {
        while(*p == ' ') p++; // skip spaces
        if(!(*p)) break;

        words[count++] = p; // save word's start
        while(*p != ' ' && *p) p++;

        if(*p == ' ') {
            *p = '\0'; // terminate word
            p++;
        }
    }
    
    for(int i = 0; i < count; i++) printf("%s\n", words[i]);
    return 0;
}