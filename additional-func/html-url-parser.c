#include<stdio.h>
#include<string.h>

int main() {
    char* save;
    char url[] = "https://site.com/path/page?x=1";
    char *token = strtok_r(url, ":", &save);
    printf("%s ", token);
    token = strtok_r(NULL, "/", &save);
    printf("%s ", token);
    token = strtok_r(NULL, "/", &save);
    printf("%s ", token?token:"");
    token = strtok_r(NULL, "?", &save);
    printf("%s %s\n", token?token:"", save?save:"");
    
    return 0;
}