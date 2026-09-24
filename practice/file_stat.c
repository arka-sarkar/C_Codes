#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define BUFFER_SIZE 8192

typedef struct {
    size_t bytes;
    size_t words;
    size_t lines;
    size_t digits;
    size_t spaces;
    int in_word;
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

content stat(const unsigned char file_content[], size_t bytes , content stats) {
    for(size_t i = 0; i < bytes; i++) {
        stats.bytes++;
        if(isdigit(file_content[i])) stats.digits++;
        if(file_content[i] == ' ') stats.spaces++;

        if(is_wc_space(file_content[i])) {
            stats.in_word = 0;
        } else if(!stats.in_word) {
            stats.words++;
            stats.in_word = 1;
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
        printf("It handles binary files with LC_ALL=C setting.\n");
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

    size_t n;
    unsigned char file_content[BUFFER_SIZE];
    content stats = {0};
    
    while((n=fread(file_content, sizeof(unsigned char), BUFFER_SIZE, file)) > 0)
        stats = stat(file_content, n, stats);

    printf("File Statistics\n");
    printf("---------------\n");
    printf("Bytes      : %zu\n", stats.bytes);
    printf("Words      : %zu\n", stats.words);
    printf("Lines      : %zu\n", stats.lines);
    printf("Digits     : %zu\n", stats.digits);
    printf("Spaces     : %zu\n", stats.spaces);

    fclose(file);
    return 0;
}