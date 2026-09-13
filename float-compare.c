#include<stdio.h>
#include<math.h>

int main(int argc, char* argv[]) {
    double a = 0.1+0.2;
    double b = 0.3;
    printf("%.17lf\n", a);
    printf("%.17lf\n", b);

    if (fabs(a-b) <= pow(10, -10)) printf("Equal\n");
    else printf("Unequal\n");
    return 0;
}