#include<stdio.h>

int main(int argc, char* argv[]) {
    int max=0, min=20, choice, mark, pos=0, sum=0, pos1=0;
    float avg;
    int marks[30]={0};
    int rollno[30]={0};
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

        switch (choice) {
            case 1:
                if(pos < 30) scanf(" %d", &marks[pos++]);
                else printf("Your have already entered the marks of all students.\n");
                break;
            
            case 2:
                printf("The marks in the order of increasing roll no. is ");
                for(int i=0; i<pos; i++) {
                    if( i != 0 ) putchar(' ');
                    printf("%d", marks[i]);
                }
                putchar('\n');
                break;
            
            case 3:
                for(int i=0; i<pos; i++) sum += marks[i];
                avg = (float)sum/pos;
                printf("The average mark is %.1f.\n", avg);
                sum = 0;
                break;

            case 4:
                for(int i=0; i<pos; i++) {
                    if(max < marks[i]) max == marks[i];
                }
                printf("The maximum marks is %d.\n", max);
                break;
            
            case 5:
                for(int i=0; i<pos; i++) {
                    if(min > marks[i]) min == marks[i];
                }
                printf("The maximum marks is %d.\n", min);
                break;
            
            case 6:
                scanf(" %d", &mark);

                for(int i=0; i<pos; i++) {
                    if(mark == marks[i]) rollno[pos1++] = pos+1;
                }
                if(rollno[0]){
                    printf("Students with roll no. ");
                    for(int i=0; i<pos1; i++) {
                        printf("%d", rollno[pos1]);
                        if(i != pos-1) printf(", ");
                    }
                    printf(" got %d marks\n", mark);
                } else printf("No students got %d marks.\n", mark);
                break;

            case 7:
                return 0;

            default:
                printf("Please enter any number from 1 to 7.\n");
                break;
        }
    }
    
    return 0;
}
