#include <stdio.h>

int main() {
    char operator;
    float num1, num2, result;

    printf("====================================\n");
    printf("      SIMPLE CALCULATOR IN C        \n");
    printf("====================================\n");
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);

    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);

    switch (operator) {
        case '+':
            result = num1 + num2;
            printf("\nResult: %.2f + %.2f = %.2f\n", num1, num2, result);
            break;

        case '-':
            result = num1 - num2;
            printf("\nResult: %.2f - %.2f = %.2f\n", num1, num2, result);
            break;

        case '*':
            result = num1 * num2;
            printf("\nResult: %.2f * %.2f = %.2f\n", num1, num2, result);
            break;

        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                printf("\nResult: %.2f / %.2f = %.2f\n", num1, num2, result);
            } else {
                printf("\nError: Division by zero is not allowed!\n");
            }
            break;

        default:
            printf("\nError: Invalid operator entered!\n");
    }

    printf("====================================\n");
    return 0;
}