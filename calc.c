#include<stdio.h>

int main(int argc, char* argv[]) {
    double a, b, res;
    char op;

    scanf("%lf %c %lf", &a, &op, &b);

    switch (op)
    {
    case '+':
        res = a + b;
        break;
    
    case '-':
        res = a - b;
        break;
    
    case '*':
        res  = a * b;
        break;

    case '/':
        res = a / b;
        break;
    
    case '%':
        res = ((int)a) % ((int)b);
        break;
    
    default:
        printf("Invalid Operation.\n");
        return 0;
    }

    printf("%lf %c %lf = %lf\n", a, op, b, res);
    return 0;
}