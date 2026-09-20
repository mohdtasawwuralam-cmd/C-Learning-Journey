#include <stdio.h>

int main() {
    int num, temp, digit;
    int count = 0, sum = 0, reversed = 0;
    printf("========================================\n");
    printf("   DAY 9 - NUMBER ANALYSIS SYSTEM      \n");
    printf("========================================\n");

    printf("Enter a positive integer; ");
    scanf("%d" , &num);

    if (num < 0) {
        printf("/nPlease enter a positve number!/n");
        return 1;
    }
    temp = num; 

    while (temp >0 ) {
        digit = temp % 10;
        sum += digit;
        reversed = reversed * 10 + digit;
        count++;

        temp /= 10;

    }

    printf("\n----------------------------------------\n");
    printf("Original Number  : %d\n", num);
    printf("Total Digits     : %d\n", count);
    printf("Sum of Digits    : %d\n", sum);
    printf("Reversed Number  : %d\n", reversed);
    printf("-------------------------------------------\n");

    if (num == reversed && num != 0) {
        printf("Result: %d is a PALINDROME number!\n", num);
    } else {
        printf("Result: %d is NOT a Palindrome number.\n", num);
    }

    printf("========================================\n");
    return 0;
}