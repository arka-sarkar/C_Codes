#include<stdio.h>

int main(int argc, char* argv[]) {
    int n;
    scanf("%d", &n);

    int num[n];
    int *ptr_num = num;
    for(int i = 0; i < n; i++) {
        scanf(" %d", ptr_num);
        ptr_num++;
    }
    ptr_num = num;
    int k;
    scanf(" %d", &k);

    for(int i = 0; i < n; i++) {
        if ((*ptr_num % 3) == 0)  *ptr_num += k;
        else *ptr_num -= k;
        ptr_num++;
    }
    ptr_num = num;
    int pos_elem = 0, total = 0;

    for(int i = 0; i < n; i++) {
        if(*ptr_num > 0) pos_elem++;
        total += *ptr_num;
        ptr_num++;
    }
    
    for(int i = 0; i < n; i++) {
        if(i != 0) putchar(' ');
        printf("%d", *(num+i));
    }
    putchar('\n');
    printf("%d %d\n", total, pos_elem);
    return 0;
}