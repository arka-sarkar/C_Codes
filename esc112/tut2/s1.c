#include<stdio.h>
#include<ctype.h>

int main() {
	char word[51];
	scanf("%49[^\n]", word);

	int length = 0, upper = 0;
	char *ptr = word;
	while(*ptr) {
	    if(isupper((unsigned char)*ptr)) upper++;
	    length++;
		ptr++;
	}
	printf("Uppercase: %d, Length: %d\n", upper, length);
	
	return 0;
}