#include<stdio.h>

typedef struct Student {
    int roll;
    int marks[3];
} student;

int main(int argc, char* argv[]) {
    student students[100];

    students[0].roll = 101;
    students[0].marks[0] = 80;

    students[1].roll = 102;
    students[1].marks[1] = 75;

    return 0;
}