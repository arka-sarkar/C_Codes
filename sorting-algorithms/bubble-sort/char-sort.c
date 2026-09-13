#include<stdio.h>
#include<ctype.h>

int main(int argc, char* argv[]) {
    char s[100], temp;
    scanf("%[^\n]",s);

    int length=0;
    for(int i=0;s[i];i++) length++;

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length-i-1; j++) {
            if(s[j+1]<s[j] && !isspace(s[j+1]) && !isspace(s[j])) {
                temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
    
    
    for (int pos = 0; pos < length; pos++) printf("%c", s[pos]); 
    
    putchar('\n');
    return 0;
}