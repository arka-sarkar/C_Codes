#include<stdio.h>
#include<stdlib.h>

int divides(int base, int n) {
    int k = 0;

    while (n%base==0) {
        n/=base;
        k++;
    }
    return k;
}

int isSpecial(int n) {
    return (divides(6, n)>divides(7, n));
}

int isarrspecial(int size, int arr[]) {
    int special = 1;
    for(int i = 0; i < size; i++) {
        if(!isSpecial(arr[i])) return special = 0;
    }
    return special;
}

int main() {
    int test_cases;
    scanf("%d", &test_cases);
    int* a[test_cases];
    int sizes[test_cases];
    for (int i = 0; i < test_cases; i++) {
        scanf(" %d", sizes+i);
        a[i] = calloc(sizes[i], sizeof(int));
        for (int j = 0; j < sizes[i]; j++) {
            scanf(" %d", &a[i][j]);
        }
    }
    int count;
    for (int i = 0; i < test_cases; i++) {
        count = 0;
        int rem = a[i][0]%6;
        for(int j = 1; j < sizes[i]; j++) {
            if(a[i][j]%6!=rem) {
                count = -1;
                goto print;
            }
        }

        if(isarrspecial(sizes[i], a[i])) goto print;
        for (int j = 0; j < sizes[i]; j++) {
            a[i][j]+=(6-rem);
        }
        count+=(6-rem);

        while (!isarrspecial(sizes[i], a[i])) {
            for (int j = 0; j < sizes[i]; j++) {
                a[i][j]+=6;
            }
            count+=6;
        }
        
        print: printf("%d\n", count);
        free(a[i]);
    }
}
