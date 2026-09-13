#include<stdio.h>
#include<string.h>

int main(int argc, char* argv[]) {
    char input1[101], input2[101];
    int c; 
    fgets(input1, 101, stdin);
    fgets(input2, 101, stdin);
    int max=0,index,k;
    for (int i = 0; i < strlen(input1)-1; i++)
    {
        printf("i=%d\n",i);
        for (int j = 0; j < strlen(input2)-1; j++)
        {
            printf("j=%d\n",j);
            for (k = 0; input1[i+k] && input2[j+k] && input1[i+k] == input2[j+k] ; k++)
            {
                if(k >= max) {
                    max = k;
                    index = i;
                }
            }
        }
    }
    printf("%d %d ", max, index);
    for(int i = index; i < index + max; i++){
        putchar(input1[i]);
    }
    putchar('\n');
    return 0;
}