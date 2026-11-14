#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool isMatch(char* s, char* p) {
    if(strlen(p)==0) return (strlen(s)==0);

    bool first_match = (strlen(s)!=0) && (p[0]==s[0] || p[0]=='.');

    if(strlen(p)>=2 && p[1]=='*') {
        return (first_match && isMatch(s+1,p))||isMatch(s, p+2);
    } else {
        return first_match && isMatch(s+1,p+1);
    }
}

int main() {
    char s[21], p[21];
    scanf("%20s %20[^\n]", s, p);
    bool match = isMatch(s, p);
    if(match) printf("true\n");
    else printf("false\n");
    return 0;
}