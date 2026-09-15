#include <stdio.h>
int main() {
    float phy, chem, math;
    float total, percentage, average;
    printf("Enter Physics marks (out of 100) ");
    scanf("%f", &phy);
    printf("Enter Chemistry marks (out of 100): ");
    scanf("%f", &chem);
    printf("Enter Mathematics marks (out of 100): ");
    scanf("%f", &math);
    total = phy + chem + math;
    average = total / 3.0;
    percentage = (total / 300.0) * 100;
    printf("Total marks: %.2f\n", total);
    printf("Average marks: %.2f\n", average);
    printf("Percentage: %.2f%%\n", percentage);
    return 0;
}