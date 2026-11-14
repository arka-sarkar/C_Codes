#include<stdio.h>
#include<string.h>

int main() {
    char line[10102];
    char words[100][101];
    int freq[100], count=0;
    fgets(line, sizeof line, stdin);
    char *token = strtok(line, " \n");
    while(token != NULL) {
        int j;
        for(j=0; j<count; j++) {
            if(strcmp(token, words[j]) == 0) break;
        }
        if(j == count) {
            strcpy(words[count], token);
            freq[count] = 1;
            count++;
        } else freq[j]++;
        token = strtok(NULL, " \n");
    }
    int best=-1;
    for(int i=0; i<count; i++) {
        if(freq[i] == 1 && (best == -1 || strlen(words[i]) > strlen(words[best]))) best=i;
    }
    printf("%s %zu\n", words[best], strlen(words[best]));
    return 0;
}