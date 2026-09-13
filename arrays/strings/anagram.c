#include <stdio.h>
#include <ctype.h>


int main(int argc, char *argv[])
{
    char word1[100], word2[100];
    int freq[128]={0};
    int isanagram=1;
    scanf("%[^\n] %[^\n]", word1, word2);
    
    for (int i = 0; word1[i]; i++) {
        char c = tolower(word1[i]);
        if(!isspace(c)) ++freq[c];
    }

    for (int i = 0; word2[i]; i++) {
        char c = tolower(word2[i]);
        if(!isspace(c)) --freq[c];
    }


    for (int i = 0; i < 128; i++) if(freq[i]) isanagram=0;
    
    if (isanagram) printf("\nAnagram\n");
    else printf("\nNot anagram\n");
    
    return 0;
}
