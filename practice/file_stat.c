#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct Content {
    size_t bytes;
    size_t words;
    size_t lines;
    size_t digits;
    size_t spaces;
} content;

int is_wc_space(unsigned char c) {
    return c == ' '  ||
           c == '\t' ||
           c == '\n' ||
           c == '\r' ||
           c == '\v' ||
           c == '\f' ||
           c == 0xA0;
}

content stat(const unsigned char file_content[], content stats) {
    int in_word = 0;
    stats.lines = stats.digits = stats.spaces = stats.words = 0;

    if(stats.bytes == 0) return stats;

    for(size_t i = 0; i < stats.bytes; i++) {
        if(isdigit(file_content[i])) stats.digits++;
        if(file_content[i] == ' ') stats.spaces++;

        if(is_wc_space(file_content[i])) {
            in_word = 0;
        } else if(!in_word) {
            stats.words++;
            in_word = 1;
        }
        if(file_content[i] == '\n') stats.lines++;
    }
    return stats;
}

int main(int argc, char* argv[]) {
    if (argc == 2 && (!strcmp(argv[1], "--help") || !strcmp(argv[1], "-h"))){
        printf("Usage: \"./file_stat <filename>\".\n");
        printf("Calculate basic statistics of a text file.\n");
        printf("Here, lines refer to no. of newline characters in the file not no. of lines percieved by humans.\n");
        printf("This is necessary so that it can handle binary files as well.\n");
        return 0;
    }

    if(argc != 2) {
        printf("Usage: \"./file_stat <filename>\".\n");
        return 1;
    }

    char* filename = argv[1];
    FILE* file = fopen(filename, "rb");
    if(file == NULL) {
        printf("The file %s doesn't exist or can\'t be accessed.\n", filename);
        return 1;
    }

    
    unsigned char* temp;
    size_t i = 0;
    size_t capacity = 100;
    unsigned char* file_content = malloc(capacity*sizeof(unsigned char));
    int ch;
    content stats;
    while((ch=fgetc(file))!=EOF) {
        if(i >= capacity) {
            capacity *= 2;
            temp = realloc(file_content, capacity*sizeof(unsigned char));

            if(temp != NULL) {
                file_content = temp;
            } else {
                free(file_content);
                fclose(file);
                printf("Insufficient space.\n");
                return 1;
            }
        }
        file_content[i] = (unsigned char)ch;
        i++;
    }
    stats.bytes = i;
    stats = stat(file_content, stats);

    printf("File Statistics\n");
    printf("---------------\n");
    printf("Bytes      : %zu\n", stats.bytes);
    printf("Words      : %zu\n", stats.words);
    printf("Lines      : %zu\n", stats.lines);
    printf("Digits     : %zu\n", stats.digits);
    printf("Spaces     : %zu\n", stats.spaces);

    free(file_content);
    fclose(file);
    return 0;
}
