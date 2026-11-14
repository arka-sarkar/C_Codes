#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define BUFFER_SIZE 4096

int main(int argc, char* argv[]) {
    if(argc == 2 && (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help"))) {
        printf("Usage: copy <source> <dest>\n");
        printf("Copies file contents from <source> to <dest>. (if <source> exists)\n");
        return 0;
    } else if(argc != 3) {
        printf("Usage: copy <source> <dest>\n");
        return 1;
    }

    char *source = argv[1], *dest = argv[2];

    if(!strcmp(source, dest)) return 0;

    FILE* file_source = fopen(source, "rb");
    if(file_source == NULL) {
        fprintf(stderr, "Either %s doesn\'t exist or access is denied.\n", source);
        return 1;
    }

    FILE* file_dest = fopen(dest, "wb");
    if(file_dest == NULL) {
        fprintf(stderr, "Access to %s is denied.\n", dest);
        return 1;
    }

    unsigned char* file_content = malloc(BUFFER_SIZE);
    if (file_content == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        fclose(file_source);
        fclose(file_dest);
        return 1;
    }
    size_t n;
    while((n = fread(file_content, 1, BUFFER_SIZE, file_source))>0){
        if(fwrite(file_content, 1, n, file_dest) != n) {
            fprintf(stderr, "Error writing content to %s.\n", dest);
            free(file_content);
            fclose(file_source);
            fclose(file_dest);
            return 1;
        };
    }
    free(file_content);
    fclose(file_source);
    fclose(file_dest);
    return 0;
}