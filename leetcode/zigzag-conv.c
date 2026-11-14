#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

char* convert(char* s, int numRows) {
    int length = strlen(s);
    char *output = malloc(length+1);
    int size=(numRows>1)?(ceil((float)length/(2*numRows-2))*numRows):length;
    char temp[numRows][size];
    for(int i=0; i<numRows; i++) for(int j=0; j<size;j++) temp[i][j]='\0';
    int i=0;
    int shouldBreak=0;
    for(int j=0; s[i];) {
        int k=0;
        for(; k<numRows; k++) {
            if(!s[i]) {
                shouldBreak=1;
                break;
            }
            temp[k][j]=s[i++];
        }
        if(shouldBreak) break;
        k-=2;
        j++;
        for(;k > 0;j++, k--) {
            if(!s[i]) {
                shouldBreak=1;
                break;
            }
            temp[k][j] = s[i++];
        }
        if(shouldBreak) break;
    }
    shouldBreak=0;
    i=0;
    for(int j=0; j<numRows; j++) {
        for(int k=0; k<size; k++) {
            if(temp[j][k] == '\0') continue;
            output[i++] = temp[j][k];
            if(!s[i]) {
                shouldBreak=1;
                break;
            }
            if(shouldBreak) break;
        }
    }
    output[i]='\0';
    return output;
}

int main() {
    char s[1001];
    int numRows;
    scanf(" %1000s %d", s, &numRows);
    char *out = convert(s, numRows);
    printf("%s\n", out);
    free(out);
    return 0;
}