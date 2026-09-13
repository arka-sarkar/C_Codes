#include<stdio.h>
#include<stdbool.h>

bool is_wsp(char c) {
    return (c == ' ' || c == '\t' || c == '\n');
}

int main(int argc, char* argv[]) {
    printf("%s\n",is_wsp('\t')?"true":"false");
    return 0;
}