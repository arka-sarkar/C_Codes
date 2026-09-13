#include<stdio.h>

void sort(int length, int num[]) {
    int key,j;
    for (int i = 1; i < length; i++) {
        key = num[i];
        j = i-1;
        while (j >= 0 && num[j] > key) {
            num[j+1]=num[j];
            j--;
        }
        num[j+1]=key;
    }
}

int main(int argc, char* argv[]) {
    int length;
    scanf("%d",&length);

    int num[length];
    for (int i = 0; i < length; i++) scanf(" %d", num+i);
    
    sort(length, num);
    for (int i = 0; i < length; i++) {
        if(i > 0) putchar(' ');
        printf("%d", num[i]);
    }
    putchar('\n');

    return 0;
}