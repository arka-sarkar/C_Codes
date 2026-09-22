#include<stdio.h>

typedef struct Student {
    int roll;
    int marks[3];
} student;


int main(int argc, char* argv[]) {
    student s;
    s.roll = 101;
    s.marks[0] = 80;
    s.marks[1] = 75;
    s.marks[2] = 90;

    printf("The student's roll no. is %d\n", s.roll);
    printf("The score in quiz 1 is %d\n", s.marks[0]);
    printf("The score in quiz 2 is %d\n", s.marks[1]);
    printf("The score in quiz 2 is %d\n", s.marks[2]);
    return 0;
}