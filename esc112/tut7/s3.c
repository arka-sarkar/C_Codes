#include<stdio.h>
#include<string.h>

// Brian Kernighan's bit-clearing loop
unsigned int count1(unsigned int n) {
    unsigned int count=0; 
    while(n) {
        n &= n-1;
        count++;
    }
    return count;
}

unsigned int size(unsigned int n) {
    unsigned int count=0;
    while(n) {
        count++;
        n>>=1;
    }
    return count;
}

int main() {
    unsigned int M, queries, pos, other_M;
    char instruction[10];
    scanf(" %u %u", &M, &queries);
    for (int i = 0; i < queries; i++) {
        scanf(" %9s", instruction);
        if(instruction[strlen(instruction)-1]=='\n') instruction[strlen(instruction)-1]='\0';
        if(!strcmp(instruction, "ADD")) {
            scanf(" %u", &pos);
            M |= (1u<<pos);
            printf("Added %u: mask=0x%08X\n", pos, M);
        } else if(!strcmp(instruction, "REMOVE")) {
            scanf(" %u", &pos);
            M &= ~(1u<<pos);
            printf("Removed %u: mask=0x%08X\n", pos, M);
        } else if(!strcmp(instruction, "CONTAINS")) {
            scanf(" %u", &pos);
            printf("Contains %u: %s\n", pos, ((M >> pos)&1u)?"YES":"NO");
        } else if(!strcmp(instruction, "COUNT")) {
            printf("Size: %d\n", count1(M));
        } else if(!strcmp(instruction, "UNION")) {
            scanf(" %u", &other_M);
            M |= other_M;
            printf("Union: mask=0x%08X size=%u\n", M, count1(M));
        } else if(!strcmp(instruction, "INTERSECT")) {
            scanf(" %u", &other_M);
            M &= other_M;
            printf("Intersection: mask=0x%08X size=%u\n", M, count1(M));
        } else if(!strcmp(instruction, "PRINT")) {
            if(M == 0) printf("Elements: EMPTY\n");
            else {
                unsigned int siz = size(M);
                int not_first=0;
                printf("Elements: ");
                for(unsigned int i=0; i<=siz; i++) {
                    if(((M>>i)&1u) == 1) {
                        if(not_first) putchar(' ');
			            else not_first=1;
                        printf("%d", i);
                    }
                }
                putchar('\n');
            }
        }
    }
    
    return 0;
}
