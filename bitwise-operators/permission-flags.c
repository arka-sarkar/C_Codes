#include<stdio.h>

#define READ (1u << 0)
#define WRITE (1u << 1)
#define EXECUTE (1u << 2)

int main() {
    unsigned int permissions = READ|WRITE;

    if(permissions & READ) printf("Read allowed\n");
    permissions |= EXECUTE; // Grant execution permission
    permissions &= ~WRITE; // Revoke write access

    if(permissions & EXECUTE) printf("Execution allowed\n");
    return 0;
}