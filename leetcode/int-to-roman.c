#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int noOfDigits(int n) {
    int count=0;
    while(n!=0) {
        count++;
        n/=10;
    }
    return count;
}

int power(int base, int exp) {
    if(exp == 0) return 1;

    int result;
    if(exp) result = power(base, exp/2);

    if(exp%2 == 0) return result*result;
    else return base*result*result;  
}

char* intToRoman(int num) {
    char *out=calloc(16,1);
    int digits=noOfDigits(num);
    int count=0, digit;
    for(int i=digits-1; i>=0; i--) {
        digit = num/power(10, i);
        switch(i) {
            case 3:
                if(digit <= 3)
                    for(int j=digit; j>0; j--) out[count++] = 'M';
                break;
            
            case 2:
                if(digit==9) {
                    strcpy(out+count, "CM");
                    count+=2;
                    break;
                } else if(digit>=5) {
                    out[count++]='D';
                    digit-=5;
                }
                if(digit<4) for(int j=digit; j>0; j--) out[count++] = 'C';
                else {
                    strcpy(out+count, "CD");
                    count+=2;
                }
                break;
            
            case 1:
                if(digit==9) {
                    strcpy(out+count, "XC");
                    count+=2;
                    break;
                } else if(digit>=5) {
                    out[count++]='L';
                    digit-=5;
                }
                if(digit<4) for(int j=digit; j>0; j--) out[count++] = 'X';
                else {
                    strcpy(out+count, "XL");
                    count+=2;
                }
                break;

            case 0:
                if(digit==9) {
                    strcpy(out+count, "IX");
                    count+=2;
                    break;
                } else if(digit>=5) {
                    out[count++]='V';
                    digit-=5;
                }
                if(digit<4) for(int j=digit; j>0; j--) out[count++] = 'I';
                else {
                    strcpy(out+count, "IV");
                    count+=2;
                }
                break;
        }
        num %= power(10,i);
    }
    out[count]='\0';
    return out;
}

int main() {
    int num;
    scanf(" %d", &num);
    char *roman = intToRoman(num);
    printf("%s\n", roman);
    free(roman);
    return 0;
}