#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdint.h>

int main(int argc, char* argv[]) {
    char* op = argv[1];
    int invalid = 0;

    if(argc == 4) {
        int64_t num2 = atol(argv[3]);
        int64_t num1 = atol(argv[2]);
        int64_t result;

        if(strcmp(op, "add") == 0) result = num1 + num2;
        else if(strcmp(op, "subtract") == 0) result = num1 - num2;
        else if(strcmp(op, "multiply") == 0) result = num1 * num2;
        else if(strcmp(op, "quotient") == 0) result = num1 / num2;
        else if(strcmp(op, "remainder") == 0) result = num1 % num2;
        else invalid = 1;

        if(invalid) {
            printf("Invalid operation.\n");
            goto quit;
        }

        printf("%d\n", result);
    } else {
        printf("Run the command in this format:\n");
        printf("./cmdline-calc <operation> <num1> <num2>\n\n");
        printf("Where <operation> can be one of the five values: add, subtract, multiply, quotient, remainder.\n");
        printf("For quotient and remainder, num1 is dividend and num2 is divisor.\n");
        printf("For the rest, the names are self-explanatory.\n");
        printf("\nIf you don't write in this format, this help message will be shown.\n");
    }
    
    quit: return 0;
}
