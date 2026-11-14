#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char** splitWordsBySeparator(char** words, int wordsSize, char separator, int* returnSize) {
    *returnSize=0;
    char** result = calloc(500, sizeof(char*));
    for(int i=0; i<500; i++) result[i] = calloc(20, sizeof(char));

    char sep[2]={separator,'\0'};
    for(int i=0; i<wordsSize; i++) {
        char *save, *token = strtok_r(words[i], sep, &save);
        while(token != NULL) {
            if(strcmp(token, "") != 0) {
                strcpy(result[*returnSize], token);
                (*returnSize)++;
            }
            token = strtok_r(NULL, sep, &save);
        }
    }
    for(int i = *returnSize; i<500; i++) free(result[i]);
    result = realloc(result, (*returnSize)*sizeof(char*));
    return result;
}

int main() {
    char *words[3];
    for(int i=0; i<3; i++) words[i]=calloc(21, 1);
    strcpy(words[0], "one.two.three");
    strcpy(words[1], "four.five");
    strcpy(words[2], "six");
    int returnSize=0;
    char **result = splitWordsBySeparator(words, 3, '.', &returnSize);
    for(int i=0; i<returnSize; i++) {
        if(i!=0) putchar(' ');
        printf("%s", result[i]);
        free(result[i]);
    }
    for(int i=0; i<3; i++) free(words[i]);
    putchar('\n');
    free(result);
    return 0;
}