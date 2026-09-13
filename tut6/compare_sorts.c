#include<stdio.h>
#include<stdlib.h>
// #include<string.h>

int bubble_sort(int numbers[], int length) {
    int buffer, swaps=0;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length-i-1; j++) {
            if(numbers[j+1]<numbers[j]) {
                swaps++;
                buffer = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = buffer;
            }
        }
    }
    return swaps;
} 

int selection_sort(int arr[], int length) {
    int min, temp, swaps=0;
    for (int i = 0; i < length-1; i++) {
        min=i;
        for (int j = i+1; j < length; j++) {
            if(arr[j] < arr[min]) min=j;
        }
        
        if(i != min) swaps++;
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    return swaps;
}

int insertion_sort(int num[], int length) {
    int key,j, shifts=0;
    for (int i = 1; i < length; i++) {
        key = num[i];
        j = i-1;
        while (j >= 0 && num[j] > key) {
            shifts++;
            num[j+1]=num[j];
            j--;
        }
        num[j+1]=key;
    }
    return shifts;
}

int main(int argc, char* argv[]) {
    int length;
    scanf("%d",&length);

    int* num = calloc(length, sizeof(int));
    for (int i = 0; i < length; i++) scanf(" %d", num+i);

    int* num_copy1 = calloc(length, sizeof(int));
    int* num_copy2 = calloc(length, sizeof(int));
    int* num_copy3 = calloc(length, sizeof(int));

    for (int i = 0; i < length; i++) num_copy1[i] = num_copy2[i] = num_copy3[i] = num[i];
    // memcpy(num_copy1, num, length*sizeof(int));
    // memcpy(num_copy2, num, length*sizeof(int));
    // memcpy(num_copy3, num, length*sizeof(int));
    
    printf("%d %d %d\n", bubble_sort(num_copy1, length), selection_sort(num_copy2, length), insertion_sort(num_copy3, length));

    for (int i = 0; i < length; i++) {
        if(i > 0) putchar(' ');
        printf("%d", num_copy1[i]);
    }
    putchar('\n');

    
    free(num);
    free(num_copy1);
    free(num_copy2);
    free(num_copy3);
    return 0;
}