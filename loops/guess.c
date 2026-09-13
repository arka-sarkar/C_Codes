#include<stdio.h>

int main(int argc, char* argv[]) {
    int guess, secret = 7;
    do {
        printf("Guess the number: ");
        scanf(" %d", &guess);
        if(guess<secret) printf("Too small!\n");
        else if(guess > secret) printf("Too large!\n");
        else printf("Correct!\n");
    } while (guess != secret);
    
    return 0;
}