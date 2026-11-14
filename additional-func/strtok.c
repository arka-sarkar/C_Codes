#include<stdio.h>
#include<string.h>

int main() {
    char sentence[50];
    fgets(sentence, 49, stdin);
    if(sentence[strlen(sentence)-1] == '\n') sentence[strlen(sentence)-1]='\0';
    int original_len = strlen(sentence);
    char* save = NULL;

    // Safe version
    char* token = strtok_r(sentence, " ", &save);
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok_r(NULL, " ", &save);
        // Works but unsafe : token = strtok(NULL, " ")
    }

    putchar('\n');
    for (int i = 0; i < original_len; i++) {
        if(sentence[i] == '\0') printf("\\0");
        putchar(sentence[i]);
    }
    putchar('\n');
    return 0;
}