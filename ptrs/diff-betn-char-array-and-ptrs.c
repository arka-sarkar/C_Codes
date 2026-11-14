#include<stdio.h>

int main() {
    char amessage[] = "hello"; // Writable memory (onto the stack)
    char *pmessage = "hello";  // Read-only memory (.rodata section)
    // pmessage[0] = 'a'; // writing to a read only memory triggers segmentation fault
    printf("%s %s\n", amessage, pmessage);
    amessage[0] = 'C';
    printf("%s %s\n", amessage, pmessage);
    pmessage = amessage;

    pmessage[0] = 'A';
    printf("%s %s\n", amessage, pmessage);
    return 0;
}