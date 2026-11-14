#include<stdio.h>
#define MAX 100

int string_len(char str[]) {
    int length = 0;
    while(str[length++]);
    if(str[length-2] != '\n') return length-1;
    else return length-2;
}

int isSubseq(char subseq[], char str[]) {
    int count = 0;
    int length_subseq = string_len(subseq);

    for(int i = 0; str[i]; i++) {
        if(str[i] == subseq[count]) count++;
    }
    if(count == length_subseq) return 1;
    else return 0;
}

int main(int argc, char* argv[]) {
    char subseq[MAX+1], str[MAX+1];
    scanf("%s %s", subseq, str);
    printf("%s\n", isSubseq(subseq,str)?"Yes":"No");
    return 0;
}