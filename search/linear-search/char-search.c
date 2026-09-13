#include<stdio.h>
#include<ctype.h>

int main(int argc, char* argv[]) {
    char key, word[100];
    scanf("%c",&key);
    scanf("%[^\n]", word);
    int index=-1;
    
    for (int i = 0; word[i]; i++) {
        if (tolower(key) == tolower(word[i])) {
            index = i;
            break;
        }    
    }
    
    if(index==-1) printf("Not found\n");
    else printf("Found at index %d\n", index);

    return 0;
}