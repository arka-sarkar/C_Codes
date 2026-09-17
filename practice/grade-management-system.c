#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void parse(FILE* ptr, int arr[], int* pos) {
    int pos1=0;
    char elem[3];
    char ch;

    while((ch=fgetc(ptr)) != EOF) {
        if(ch == ' ') {
            elem[pos1++]='\0';
            arr[(*pos)++] = atoi(elem);
            pos1 = 0;
        } else {
            elem[pos1++] = ch;
        }
    }    
}

char* grade(int mark) {
    int percentage = mark*5;
    char* grade;
    if(percentage > 90) grade = "A+";
    else if(percentage > 80) grade = "A";
    else if(percentage > 70) grade = "B+";
    else if(percentage > 60) grade = "B";
    else if(percentage > 50) grade = "C";
    else if(percentage > 40) grade = "D";
    else grade = "F";
    return grade;
}

int main(int argc, char* argv[]) {
    int max=0, min=20, choice, pos=0, sum=0, pos1=0, roll;
    char mark[3];
    char* file = "marks.txt";
    char status[5];
    float avg;
    int marks[30]={0};
    int rollno[30]={0};

    FILE* ptr = NULL;

    while (1) {
        printf("\n===== STUDENT MARKS =====\n");
        printf("1. Enter Marks\n");
        printf("2. Display Marks\n");
        printf("3. Calculate Average\n");
        printf("4. Find Highest Mark\n");
        printf("5. Find Lowest Mark\n");
        printf("6. Search for a Mark\n");
        printf("7. Calculate grade for a particular roll no.\n");
        printf("8. Check whether a student with a particular roll no. passed or failed\n");
        printf("9. Exit\n");
        
        printf("\nEnter the corresponding number for the choice: ");
        scanf(" %d", &choice);

        ptr = fopen(file ,"r");
        parse(ptr, marks, &pos);

        switch (choice) {
            case 1:
                if(pos < 30) {
                    scanf(" %d", &marks[pos++]);
                    if(marks[pos-1] >= 0 && marks[pos-1] <= 20) {
                        ptr = fopen(file ,"a");
                        fprintf(ptr, "%d ", marks[pos-1]);
                        fflush(ptr);
                    } else printf("Enter a marks from 0 to 20.\n");
                } else printf("Your have already entered the marks of all students.\n");
                break;
            
            case 2:
                if(pos > 0) {
                    printf("The marks in the order of increasing roll no. is ");
                    for(int i=0; i<pos; i++) {
                        printf("%d", marks[i]);
                        if(i != pos-1) printf(", ");
                    }
                    printf(".\n");
                } else printf("You haven\'t entered any marks yet.\n");
                break;
            
            case 3:
                for(int i=0; i<pos; i++) sum += marks[i];
                avg = (float)sum/pos;
                printf("The average mark is %.2f.\n", avg);
                sum = 0;
                break;

            case 4:
                for(int i=0; i<pos; i++) {
                    if(max < marks[i]) max = marks[i];
                }
                printf("The maximum marks is %d.\n", max);
                break;
            
            case 5:
                for(int i=0; i<pos; i++) {
                    if(min > marks[i]) min = marks[i];
                }
                printf("The maximum marks is %d.\n", min);
                break;
            
            case 6:
                scanf(" %[^\n]", mark);

                for(int i=0; i<pos; i++) {
                    if(atoi(mark) == marks[i]) rollno[pos1++] = i+1;
                }
                if(rollno[0]){
                    if(pos1 > 1) {
                        printf("Students with roll no. ");
                        for(int i=0; i<pos1; i++) {
                            printf("%d", rollno[i]);
                            if(i != pos1-1) printf(", ");
                        }
                        printf(" got %s marks.\n", mark);
                    } else printf("Student with roll no. %d got %s marks.", rollno[0], mark);
                } else printf("No students got %s marks.\n", mark);
                for(int i = 0; i < pos1; i++) rollno[i]=0;
                pos1 = 0;
                break;
            
            case 7:
                scanf(" %d", &roll);
                if(roll <= pos) printf("The grade of student with roll no. %d is %s.\n", roll, grade(marks[roll-1]));
                else printf("The marks of the student with roll no. %d is not entered yet.\n", roll);
                break;
            
            case 8:
                scanf(" %d", &roll);
                if(roll <= pos){
                    if(marks[roll] > 8) strncpy(status, "pass", 5);
                    else strncpy(status, "fail", 5);
                    printf("The student with roll no %d has %sed.\n", roll, status);
                } else printf("The marks of the student with roll no. %d is not entered yet.\n", roll);
                break;
                
            case 9:
                goto quit;

            default:
                printf("Please enter any number from 1 to 8.\n");
                break;
        }
        pos = 0;
    }
    
    quit:
    fclose(ptr);
    return 0;
}
