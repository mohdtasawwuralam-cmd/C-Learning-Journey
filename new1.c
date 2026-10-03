#include <stdio.h>

int main() {
    int sub1, sub2, sub3, sub4, sub5;
    float total, percentage;
    char grade;
    printf("Enter marks obtained in five subjects: ");
    scanf("%d%d%d%d%d", &sub1, &sub2, &sub3, &sub4, &sub5);
    
    total = sub1 + sub2 + sub3 + sub4 + sub5;
    percentage = (total / 500.0) * 100.0;

   if (percentage >= 90) {
    grade = 'A';
}
else if (percentage >= 80 && percentage < 90) {
    grade = 'B';
}
else if (percentage >= 70 && percentage < 80) {
    grade = 'C';
}
else if (percentage >= 60 && percentage < 70) {
    grade = 'D';
}
else if (percentage >= 40 && percentage < 60) {
    grade = 'E';
}
else {
    grade = 'F';
}
    printf("\n--- FINAL ACADEMIC REPORT ---\n");
    printf("Total Marks: %.2f\n", total);
    printf("Percentage: %.2f%%\n", percentage);
    printf("Grade: %c\n", grade);

    return 0;
}
   