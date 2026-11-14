#include<stdio.h>

int isDigit(char c) {
    return (c>='0')&&(c<='9');
}

int isSpace(char c) {
    return (c==' ')||(c=='\n')||(c=='\t');
}

int atoi(char c[]) {
    int i, sign, val;
    for(i=0; isSpace(c[i]); i++);

    sign = (c[i]=='-')?(-1):1;

    if(c[i]=='-'||c[i]=='+') i++;

    for(val = 0; isDigit(c[i]); i++) {
        val = val*10 + (c[i]-'0');
    }
    return sign*val;
}

int main(int argc, char const *argv[]) {
    char num[102];
    fgets(num, 101, stdin);
    printf("%d\n", atoi(num));
    return 0;
}
