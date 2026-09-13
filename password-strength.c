#include <stdio.h>
#include <ctype.h>

typedef char* string;

int main()
{
    int count=0, score=0;
    string strength;
    char c;
    int upper=0, lower=0, digit=0, special=0;
    while((c=getchar())!=EOF) {
        score+=2;
        
        if(isalpha(c)) score+=3;
        else if(isdigit(c)) score+=4;
        else if(!isspace(c)) score+=5;
        
        count++;
        
        if(!upper && isupper(c)) upper=1;
        if(!lower && islower(c)) lower=1;
        if(!digit && isdigit(c)) digit=1;
        if(!special && !isspace(c) && !isalnum(c) && isprint(c)) special=1;
    }
    
    if(upper && lower) score+=10;
    if(digit && special) score+=10;
    if(upper && lower && digit && special) score+=20;
    if(count>=12) score+=15;
    if(count<6) score-=10;
    
    if(score<30) strength="WEAK";
    else if(score<60) strength="MEDIUM";
    else if(score<90) strength="STRONG";
    else strength="VERY STRONG";
    
    printf("%d %s\n", score, strength);
}