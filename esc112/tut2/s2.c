#include<stdio.h>
#include<string.h>

int main() {
	char word1[50], word2[50], word3[50];
	char *p1 = word1, *p2 = word2, *p3 = word3;
	char* arr[3] = {p1, p2, p3};
	scanf("%s %s %[^\n]", p1, p2, p3);
	
	char* min = arr[0];
	for(int i = 1; i < 3; i++) {
	    if(strcmp(min, arr[i])>0) strcpy(min, arr[i]);
	}
	strcat(min, "_min");
	
	printf("%s\n", min);
	return 0;
}