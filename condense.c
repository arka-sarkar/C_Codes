#include<stdio.h>
#include<ctype.h>

int main(int argc, char* argv[]) {
    char curr, prev='\0';
    int n=1, first=1, l=0, length=0;
    while ((curr=getchar())!=EOF && !isspace(curr)) {
        
        if(prev==curr) n++;
        else {
            if(n>=2) {
                printf("%c%d", prev, n);
                n=1;
                l+=2;
            }
            else {
                if(!first) {
                    printf("%c",prev);
                    l++;
                } else first=0;
            }
        }
        length++;
        prev=curr;
    }


    if(n>=2) {
        printf("%c%d", prev, n);
        n=1;
        l+=2;
    } else {
        if(!first) {
            printf("%c",prev);
            l++;
        }
    }
        

    printf(" %d %d\n",l, length);
    return 0;
}