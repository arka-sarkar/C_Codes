#include<stdio.h>
#include<string.h>

int balancedStringSplit(char* s) {
    int countL = 0, countR = 0, count = 0;
    for (int i = 0; i < strlen(s); i++) {
        if(s[i] == 'L') countL++;
        else if(s[i] == 'R') countR++;

        if(countL == countR) count++;
    }
    return count;
}

int main() {
    char input[21];
    scanf(" %20s", input);
    int num = balancedStringSplit(input);
    printf("%d\n", num);
    return 0;
}