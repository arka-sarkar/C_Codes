#include<stdio.h>

int main(int argc, char* argv[]) {
    int key,n,num;
    scanf("%d %d", &key, &n);
    int index=-1;
    for (int i = 0; i < n; i++)
    {
        scanf(" %d", &num);
        if(num==key) {index=i+1; break;}
    }
    
    if(index==-1) printf("Not found\n");
    else printf("Found at index %d\n", index);
    return 0;
}