#include<stdio.h>
#include<string.h>

int main() {
    char sentence[10101];
    char words[101][100];
    int freq[100];
    fgets(sentence, sizeof sentence, stdin);
    char *save;
    char *token = strtok_r(sentence, " \n", &save);
    int count = 0;

    while (token != NULL) {
        int j;
        for(j=0; j<count; j++) if(strcmp(words[j], token) == 0) break;

        if(j == count) {
            strcpy(words[count], token);
            freq[count] = 1;
            count++;
        } else freq[j]++;
        token = strtok_r(NULL, " \n", &save);
    }
    
    int best=-1;

    for(int i=0; i<count; i++) {
        if(freq[i]==1 && (best==-1 || strlen(words[i])>strlen(words[best]))) best=i;
    }

    printf("%s %zu\n", words[best], strlen(words[best]));

    return 0;
}