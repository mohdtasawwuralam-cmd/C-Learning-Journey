#include <stdio.h>
int main() {
    int num, sum = 0;
    printf("=== Day 3: Multi-Utility NUmber Tool ===\n");
    printf("Enter a positive number: ");
    scanf("%d", &num);

    if (num<= 0) {
        printf("Please enter a number greater than 0.\n");
        return 1;
    }

    if (num % 2 == 0) {
        printf("%d is an even number.\n", num);
    } else {
        printf("%d is an odd number.\n", num);
    }
    printf("/n--- MUltiplication Table of %d ---\n", num);
    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", num, i, num * i);
    }

    int count = 1;
    while (count <= num) {
        sum += count;
        count++;
    }
    printf("/n--- Sum Calculation ---\n");
    printf("The sum of numbers from 1 to %d is: %d\n", num, sum);
    return 0;
}