#include<stdio.h>
#include<string.h>

void shiftLeft(char *s) {
    s[0] = s[1];
    if(strlen(s) == 0) return;
    shiftLeft(s+1);
}

int count_char(const char *s, char c) {
    char s1[20];
    strcpy(s1, s);
    if(strlen(s1) == 0) {
        return 0;
    } else {
        char a = s1[0];
        shiftLeft(s1);
        if(a == c) {
            return 1+count_char(s1, c);
        } else return count_char(s1, c);
    }
}

int is_subsequence(const char *s1, const char *s2) {
    char s1_copy[20], s2_copy[20];
    strcpy(s1_copy, s1);
    strcpy(s2_copy, s2);
    if(strlen(s2_copy) == 0) {
        if(strlen(s1_copy)==0) return 1;
        else return 0;
    }

    if(s1_copy[0] == s2_copy[0]) {
        shiftLeft(s1_copy);
    }
    shiftLeft(s2_copy);
    return is_subsequence(s1_copy, s2_copy);
}

void remove_consecutive_duplicates(char *s) {
    int length = strlen(s);
    if(length == 1 || length == 0) return;

    if(s[0] == s[1]) {
        shiftLeft(s);
        remove_consecutive_duplicates(s);
    } else remove_consecutive_duplicates(s+1);
    
}

int main() {
    char s1[20], s2[20], c;
    scanf(" %s %s %c", s1, s2, &c);
    int count = count_char(s1, c);
    printf("Count %c in s1: %d\n", c, count);
    int issubseq = is_subsequence(s1, s2);
    printf("Is s1 a subsequence of s2: %s\n", issubseq?"YES":"NO");
    remove_consecutive_duplicates(s2);
    printf("s2 after deduplication: %s\n", s2);
    return 0;
}