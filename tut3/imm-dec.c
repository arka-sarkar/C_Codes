#include<stdio.h>

int main(int argc, char* argv[]) {
    int previous, current, drops=0;

    scanf("%d", &current);
    if (current==-1)
    {
        printf("0\n");
        return 0;
    }
    
    previous = current;
    while(1) {
        scanf(" %d", &current);
        if(current==-1) break;
        if(current < previous) drops++;
        previous = current;
    }
    
    printf("%d\n", drops);
    return 0;
}