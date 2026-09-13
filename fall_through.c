#include<stdio.h>

int main(int argc, char* argv[]) {
    int d;
    scanf(" %d", &d);

    switch(d) {
    case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:
        printf("Input is between 0 and 9.\n");
        return 0;
    
    default:
        printf("Input is something else.\n");
        return 0;
    }
}