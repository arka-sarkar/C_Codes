#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct Content {
    int characters;
    int words;
    int lines;
    int digits;
    int spaces;
} content;

void trim(char str[]) {
    int length=strlen(str);
    int last;
    for(last = length-1; isspace(str[last]); last--);
    str[last+1] = '\0'; // Removes trailing spaces, last finds of the index of last non-whitespace character.

    int first;
    for(first = 0; isspace(str[first]); first++); // first finds the index of first non-whitespace character.

    for(int j = 0; j <= last-first+1; j++) str[j] = str[first+j]; // Shifts the remaining section to start.
}

content stat(char file_content[]) {
    content stats;
    stats.lines = stats.digits = stats.spaces = stats.words = 0;
    stats.characters = strlen(file_content);
    for(int i = 0; file_content[i]; i++) {
        if(file_content[i] == '\n') stats.lines++;
        if(isdigit(file_content[i])) stats.digits++;
        if(file_content[i] == ' ') stats.spaces++;
    }
    trim(file_content);
    for(int i = 0; file_content[i]; i++) {
        if(i != 0 && isspace(file_content[i]) && !isspace(file_content[i-1])) stats.words++;
    }
    stats.words++;
    return stats;
}

int main(int argc, char* argv[]) {
    if ( argc > 2 ||argc == 1 || ((argc == 2) && ((!strcmp(argv[1], "--help")) || (!strcmp(argv[1], "-h"))))){
        printf("Run it like \"./file_stat <filename>\".\n");
        goto quit;
    }
    
    char* filename = argv[1];
    FILE* file = fopen(filename, "r");
    if(file == NULL) {
        printf("The file %s doesn't exist.\n", filename);
        return 1;
    }

    char* file_content = calloc(100, sizeof(char));
    char* temp;
    int i = 0;
    char ch;
    while((ch=fgetc(file))!=EOF) {
        if(i >= 100) {
            temp = realloc(file_content, (i+1)*sizeof(char));

            if(temp != NULL) {
                file_content = temp;
            } else {
                perror("Insufficient space.\n");
                return 1;
            }
        }
        file_content[i] = ch;
        i++;
    }
    file_content[i] = '\0';

    content stats = stat(file_content);

    printf("File Statistics\n");
    printf("---------------\n");
    printf("Charcters  : %d\n", stats.characters);
    printf("Words      : %d\n", stats.words);
    printf("Lines      : %d\n", stats.lines);
    printf("Digits     : %d\n", stats.digits);
    printf("Spaces     : %d\n", stats.spaces);

    free(file_content);
    fclose(file);
    quit: return 0;
}