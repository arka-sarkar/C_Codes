#include<stdio.h>
#include<string.h>
#include<ctype.h>

char* decodeString(char* s) {
    int length=strlen(s);
    char res[100001], part[1000];
    int k=0, count=0, count1=0, count2=0;
    int isword=1;
    for(int i=0; i<length; i++) {
        if(!isalpha(s[i])) {
            isword=0;
            break;
        }
    }
    if(isword) return s;
    
    for(int i=0; i<length-1; i++) {
        if(isalpha(s[0]) && i==0) {
            while(!isdigit(s[i]) && s[i]!='\0') res[count++] = s[i++];
        }

        if(isdigit(s[i]) && isdigit(s[i+1])) {k = k*10 + (s[i]-'0'); continue;}
        else if(isdigit(s[i]) && s[i+1]=='[') {
            k = k*10 + (s[i]-'0');
            int j=0;
            i+=2;
            count1++;
            do {
                part[j++] = s[i++];
                if(s[i]=='[') count1++;
                else if(s[i]==']') count2++;
            } while(count1 != count2);
            part[j]='\0';
            for(int l=0; l<k; l++) {
                strcpy(res+count, part);
                count += j;
            }
        } 
        if(s[i] == ']' && islower(s[i+1]) && s[i+1]!='\0') {
            i++;
            while(!isdigit(s[i]) && s[i] != '\0') {
                res[count++] = s[i++];
            }
            i--;
        }
        k=0;
    }
    res[count]='\0';
    return decodeString(res);
}

int main() {
    char s[31];
    scanf("%30s",s);
    char *res = decodeString(s);
    printf("%s\n", res);
    return 0;
}