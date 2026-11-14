#include<stdio.h>
#include<string.h>

int main() {
	char main_string[51], sub_string[51];
	scanf("%s %[^\n]", main_string, sub_string);
	char* p = strstr(main_string, sub_string);
	if(p != NULL) printf("Index: %zu\n", p-main_string);
	else printf("Not found\n");
	return 0;
}