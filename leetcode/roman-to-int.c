#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<regex.h>

int romanToInt(char* s) {
    regex_t re;
    char *pattern = "^M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$";
    int rc = regcomp(&re, pattern, REG_EXTENDED|REG_NOSUB);
    if(rc) {
        char buf[128];
        regerror(rc, &re, buf, sizeof buf);
        fprintf(stderr, "regcomp: %s\n", buf);
        exit(1);
    }

    if(regexec(&re, s, 0, NULL, 0)!=0 || strlen(s)==0) {
        fprintf(stderr, "Please enter a valid Roman numeral.\n");
        return -1;
    }
    regfree(&re);

    int length=strlen(s);
    int num=0;
    for(int i=length-1; i>=0; i--) {
        if(i>=1 && s[i] == 'X' && s[i-1]=='I') {num+=9; i--;}
        else if(i>=1 && s[i] == 'V' && s[i-1]=='I') {num+=4; i--;}
        else if(s[i] == 'I') num+=1;
        else if(s[i] == 'V') num+=5;

        else if(i>=1 && s[i] == 'C' && s[i-1]=='X') {num+=90; i--;}
        else if(i>=1 && s[i] == 'L' && s[i-1] == 'X') {num+=40; i--;}
        else if(s[i] == 'X') num+=10;
        else if(s[i] == 'L') num+=50;

        else if(i>=1 && s[i] == 'M' && s[i-1]=='C') {num+=900; i--;}
        else if(i>=1 && s[i] == 'D' && s[i-1] == 'C') {num+=400; i--;}
        else if(s[i] == 'C') num+=100;
        else if(s[i] == 'D') num+=500;

        else if(s[i] == 'M') num+=1000;
    }
    return num;
}

int main() {
    

    char roman[16];
    scanf("%15[^\n]", roman);
    int c = getchar();
    int num=romanToInt(roman);
    if(c==EOF) putchar('\n');
    if(num != -1) printf("%d\n", num);

    return 0;
}