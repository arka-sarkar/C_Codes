#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]) {
    int max=0, min=20, choice, pos=0, sum=0, pos1=0;
    char mark[3];
    char* file = "marks.txt";
    float avg;
    int marks[30]={0};
    int rollno[30]={0};

    FILE* ptr = NULL;
    
    char ch;

    while (1) {
        printf("\n===== STUDENT MARKS =====\n");
        printf("1. Enter Marks\n");
        printf("2. Display Marks\n");
        printf("3. Calculate Average\n");
        printf("4. Find Highest Mark\n");
        printf("5. Find Lowest Mark\n");
        printf("6. Search for a Mark\n");
        printf("7. Exit\n");
        
        printf("\nEnter the corresponding number for the choice: ");
        scanf(" %d", &choice);

        ptr = fopen(file ,"r");
        while((ch=fgetc(ptr)) != EOF) {
            if(ch == ' ') {
                mark[pos1++]='\0';
                marks[pos++] = atoi(mark);
                pos1 = 0;
            } else {
                mark[pos1++] = ch;
            }
        }

        switch (choice) {
            case 1:
                if(pos < 30) {
                    scanf(" %d", &marks[pos++]);
                    ptr = fopen(file ,"a");
                    fprintf(ptr, "%d ", marks[pos-1]);
                    fflush(ptr);
                }
                else printf("Your have already entered the marks of all students.\n");
                break;
            
            case 2:
                printf("The marks in the order of increasing roll no. is ");
                for(int i=0; i<pos; i++) {
                    printf("%d", marks[i]);
                    if(i != pos-1) printf(", ");
                }
                printf(".\n");
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
                goto quit;

            default:
                printf("Please enter any number from 1 to 7.\n");
                break;
        }
        pos = 0;
    }
    
    quit:
    fclose(ptr);
    return 0;
}
