#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>

typedef struct Student {
    uint8_t rollno;
    char name[50];
    uint8_t marks;
    enum Grade grade;
} student;

typedef enum Grade{ A, B, C, FAIL };

void parse(FILE* ptr, unsigned short arr[], int* pos) {
    int pos1=0;
    char elem[3];
    char ch;

    while((ch=fgetc(ptr)) != EOF) {
        if(ch == ' ') {
            elem[pos1++]='\0';
            arr[(*pos)++] = (unsigned short) atoi(elem);
            pos1 = 0;
            strncpy(elem, "", 3);
        } else {
            elem[pos1++] = ch;
        }
    }    
}

int assignGrades(unsigned int mark) {
    int percentage = mark*5;
    char* grade;
    if(percentage > 90) grade = A;
    else if(percentage > 70) grade = B;
    else if(percentage > 50) grade = C;
    else grade = FAIL;
    return grade;
}



int main() {
    uint16_t max=0, min=20, choice, pos=0, sum=0, pos1=0, roll;
    char mark[3];
    char* file1 = "marks.txt";
    char* file2 = "names.txt";
    double avg;
    student students[20];

    FILE* ptr = NULL;
    
    do {
        printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Find Highest Marks\n");
        printf("5. Find Lowest Marks\n");
        printf("6. Calculate Average\n");
        printf("7. Exit\n");

        printf("\nEnter the corresponding number for the choice: ");
        if(!scanf(" %u", &choice)) {
            printf("Please don\'t enter anything other than a postive integer.\n");
            return 1;
        }

        switch(choice) {

        }
    } while (choice != 7);
    
    
    return 0;
}