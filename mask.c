#include <stdio.h>
#include <stdbool.h>

int main()
{
    char string[100], substring[100];
    int len1=0, len2=0;
    
    scanf("%[^\n] %s", string, substring);
    
    for(int i=0; string[i]; i++) len1++;
    for(int i=0; substring[i]; i++) len2++;
    int matches=0;
    bool matched;
    
    for(int i=0; i <= len1-len2; i++) {
        matched=true;
        if(string[i] == substring[0]) {
            for(int j=1; j<len2; j++) if(string[i+j]!=substring[j]) matched=false;
            
            if(matched) {
                for(int j=0; j<len2; j++) string[i+j]='*';
                i+=len2-1;
                matches++;
            }
        }
    }
    

    printf("%d %s\n", matches, string);
    return 0;
}