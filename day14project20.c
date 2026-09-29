#include <stdio.h>

int main() {
    int totalclasses, attendedclasses;
    float attendancepercentage;
    int numsubjects;
    float marks, totalmarks = 0, averagemarks;
    char grade;

    printf("===================================================\n");
    printf("   STUDENT ATTENDANCE & PERFORMANCE SYSTEM\n");
    printf("===================================================\n\n");

    printf("--- 1. ATTENDANCE CHECK ---\n");
    printf("Enter Total classes Held : ");
    scanf("%d", &totalclasses);
    printf("Enter Classes Attended : ");
    scanf("%d", &attendedclasses);

    if (totalclasses <= 0 || attendedclasses < 0 || attendedclasses > totalclasses)  {
        printf("\nError Invalid attendance inputs!\n");
        return 1;
    }

    attendancepercentage = ((float)attendedclasses / totalclasses) * 100;
    printf("Attended Percentage: %.2f%%\b", attendancepercentage);

    if (attendancepercentage >= 75.0) {
        printf("Student is eligible for exams!\n\n");
    } else {
        printf("Student is not eligible for exam");
    }

    printf("--- 2. ACADEMIC MARKS & GRADE EVALUATION---\n");
    printf("Enter number of subjects: ");
    scanf("%d", &numsubjects);

    for (int i = 1; i <= numsubjects; i++) {
        printf("Enter marks for subject %d (out of 100) : ", i);
        scanf("%f", &marks);

        while (marks < 0 || marks > 100) {
            printf("Invalid marks! Enter again (0-100): ");
            scanf("%f", &marks);

        }
        totalmarks += marks;
    }

    averagemarks = totalmarks / numsubjects;

    if (averagemarks >= 90) grade = 'A';
    else if (averagemarks >= 75) grade = 'B';
    else if (averagemarks >= 60) grade = 'C';
    else if (averagemarks >= 40) grade = 'D';
    else grade = 'F';

    printf("\n===================================================\n");
    printf("              FINAL ACADEMIC REPORT                \n");
    printf("===================================================\n");
    printf("Attendance Status : %.2f%%\n", attendancepercentage);
    printf("Total Marks    : %.2f / %d\n" , totalmarks, numsubjects * 100);
    printf("Average Marks     : %.2f%%\n", averagemarks);
    printf("Overall Grade     : %c\n", grade);
    
    if (grade != 'F' && attendancepercentage >= 75.0) {
        printf("Final Result      : PASSED & PROMOTED!\n");
    } else {
        printf("Final Result      : NEEDS IMPROVEMENT / DETAINED\n");
    }
    printf("===================================================\n");

    return 0;

}
