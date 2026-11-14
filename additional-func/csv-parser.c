#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
    char input[16], *save;
    fgets(input, 15, stdin);
    int rollno = atoi(strtok_r(input, ",", &save));
    int marks1 = atoi(strtok_r(NULL, ",", &save));
    int marks2 = atoi(strtok_r(NULL, ",", &save));
    int marks3 = atoi(strtok_r(NULL, ",", &save));
    float average = (marks1+marks2+marks3)/3.0;
    printf("Roll no: %d, Average: %.2f\n", rollno, average);
    return 0;
}