#include<stdio.h>

int main(int argc, char* argv[]) {
    int length, buffer;
    scanf("%d",&length);

    int numbers[length];
    for (int pos = 0; pos < length; pos++) scanf(" %d", numbers+pos);
    
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length-i-1; j++) {
            if(numbers[j+1]<numbers[j]) {
                buffer = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = buffer;
            }
        }
    }
    
    
    for (int pos = 0; pos < length; pos++)
    {
        if(pos!=0) printf(" ");
        printf("%d", numbers[pos]); 
    }
    putchar('\n');

    return 0;
}