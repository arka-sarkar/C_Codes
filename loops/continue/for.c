#include<stdio.h>

int main(int argc, char* argv[]) {
    for (int i = 0; i < 5; i++)
    {
        if(i == 2) continue;
        printf("%d\n", i);
    }
    
    return 0;
}