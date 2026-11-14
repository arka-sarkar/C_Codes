#include<stdio.h>
#define MAX 200

int string_len(char str[]) {
    int length = 0;
    while(str[length++]);
    return length-1;
}

void reverse(char str[]) {
    char temp;
    int length = string_len(str);

    if(str[length-1] == '\n') length--;
    for(int i=0; i < (int)(length/2); i++) {
        temp = str[i];
        str[i] = str[length-1-i];
        str[length-i-1] = temp;
    }
}

int main(int argc, char* argv[]) {
    int j, count;
    char input[MAX+1];
    char word[MAX+1];
    fgets(input, MAX, stdin);

    reverse(input);

    for(int i = 0; input[i]; i=j+1) {
        for(int k = 0; word[k]; k++) word[k] = '\0';
        count = 0;
        for(j = i; input[j] != ' ' && input[j]; j++) {
            word[count++] = input[j];
        }
        word[count]='\0';
        reverse(word);
        count = 0;
        for(j = i; input[j] != ' ' && input[j]; j++) {
            input[j] = word[count++];
        }
    }

    printf("%s", input);
        
    return 0;
}