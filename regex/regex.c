#include<stdio.h>
#include<stdlib.h>
#include<regex.h>

#define NUM_MATCHES 3

int main(int argc, char *argv[]) {
    regex_t re;
    regmatch_t match[NUM_MATCHES];
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <string to match>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char* pattern="^([a-zA-Z]+)=([a-zA-Z0-9_]+)$";
    int rc = regcomp(&re, pattern, REG_EXTENDED);
    if(rc) {
        char buf[128];
        regerror(rc, &re, buf, sizeof buf);
        fprintf(stderr, "regcomp: %s\n", buf);
        return EXIT_FAILURE;
    }
    rc = regexec(&re, argv[1], NUM_MATCHES, match, 0);
    if(!rc) {
        printf("Match!\n");
    } else if (rc == REG_NOMATCH) {
        printf("No Match!\n");
    } else {
        fprintf(stderr, "regexec failed.\n");
        return EXIT_FAILURE;
    }
    regfree(&re);
    return EXIT_SUCCESS;
}