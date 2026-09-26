#include <stdio.h>

int main() {
    int S1, S2, S3, S4, S5;
    float average;
    printf("Enter marks of S1 : ");
    scanf("%d", &S1);
    printf("Enter marks of S2 :");
    scanf("%d", &S2);
    printf("Enter marks of S3 :");
    scanf("%d", &S3);
    printf("Enter marks of S4 :");
    scanf("%d", &S4);
    printf("Enter marks of S5 :");
    scanf("%d", &S5);
    average = (S1 + S2 + S3 + S4 + S5) / 5.0;
    printf("Average marks of 5 subject is : %.2f\n", average);
    return 0;
}