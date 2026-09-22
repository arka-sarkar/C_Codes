#include<stdio.h>

typedef struct Student {
    int roll;
    int marks[3];
} student;

int calculateTotal(student s) {
    int total = 0;
    for(int i = 0; i < 3; i++) total += s.marks[i];
    return total;
}

int findBest(student students[], int n) {
    int bestIndex = 0;

    for(int i = 0; i < n; i++){
        int currentTotal = calculateTotal(students[i]);
        int bestTotal = calculateTotal(students[bestIndex]);

        if(currentTotal > bestTotal) bestIndex = i;
    }

    return bestIndex;
}

int main(int argc, char* argv[]) {
    student students[100];
    int n;
    scanf("%d",&n);

    for (int i = 0; i < n; i++) {
        scanf(" %d", students[i].roll);
        
        for(int j = 0; j < 3; j++) {
            scanf(" %d", &students[i].marks[j]);
        }
    }

    printf("The roll no. of student with highest total marks is %d.\n", findBest(students, n)+1);
    return 0;
}