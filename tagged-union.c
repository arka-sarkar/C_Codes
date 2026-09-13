#include<stdio.h>

typedef struct value {
    int type; // 0->int 1->float
    union {
        int i;
        float f;
    } data;
} Value;


int main(int argc, char* argv[]) {
    Value v;
    v.type=0;
    v.data.i=100;
    return 0;
}