#include<stdio.h>
#include<stdlib.h>

int main() {
	int size;
	scanf("%d", &size);

	int *arr = calloc(size, sizeof(int));
	if(arr == NULL) {
	    fprintf(stderr, "Allocation failed.\n");
		return 1;
	}

	
	for (int i = 0; i < size; i++) {
	    scanf(" %d", arr+i);
	}
	int j = 1;
	for (int i = 1; i < size; i++) {
	    if(arr[i]!=arr[i-1]) arr[j++] = arr[i];
	}
	int *temp = realloc(arr, j*sizeof(int));

	if(temp == NULL) {
        fprintf(stderr, "Reallocation failed.\n");
        return 1;
	} else arr = temp;
	
	printf("%d\n", j);
	for (int i = 0; i < j; i++) {
	    if(i != 0) putchar(' ');
		printf("%d", arr[i]);
	}
	free(arr);
	putchar('\n');
	return 0;
}