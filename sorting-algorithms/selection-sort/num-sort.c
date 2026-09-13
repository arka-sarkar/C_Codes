#include<stdio.h>

int main(int argc, char* argv[]) {
    int length, temp, min;
    scanf("%d",&length);

    int arr[length];
    for(int i=0; i<length; i++) scanf(" %d", arr+i);

    for (int i = 0; i < length-1; i++) {
        min=i;
        for (int j = i+1; j < length; j++) {
            if(arr[j] < arr[min]) min=j;
        }
        
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    
    for (int i = 0; i < length; i++) {
        if(i!=0) putchar(' ');
        printf("%d",arr[i]);
    }
    putchar('\n');
    return 0;
}