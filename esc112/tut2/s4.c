#include<stdio.h>
#include<string.h>

void swap(char** a, char **b) {
    char* temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    char email1[101], email2[101], email3[101], email4[101];
    scanf("%100s %100s %100s %100[^\n]", email1, email2, email3, email4);
    char* full_ptrs[4] = {email1, email2, email3, email4};
    char* domain_ptrs[4];
    for(int i = 0; i < 4; i++) {
        domain_ptrs[i] = strchr(full_ptrs[i], '@');
        if(domain_ptrs[i] == NULL) {
            fprintf(stderr, "Write a valid email address. It must contain @ and be of the format <username>@<domain>.\n");
            return 1;
        }
        domain_ptrs[i]++;
    }

    for(int i = 0; i <= 2; i++) {
        for(int j = 0; j <= 2-i; j++) {
            if(strcmp(domain_ptrs[j], domain_ptrs[j+1])>0) {
                swap(&domain_ptrs[j], &domain_ptrs[j+1]);
                swap(&full_ptrs[j], &full_ptrs[j+1]);
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        if(i) putchar(' ');
        printf("%s", full_ptrs[i]);
    }
    putchar('\n');
	return 0;
}