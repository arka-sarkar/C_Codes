#include<stdio.h>

typedef struct Student {
    int roll;
    int marks[3];
} student;

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
    
    return 0;
}