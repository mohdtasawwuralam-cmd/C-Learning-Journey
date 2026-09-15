#include <stdio.h> 

int main() {
    int units;
    float total_bill = 0.0;

    printf("=== Electricity Bill Calculator ===\n");
    printf("Enter total units consumed: ");
    scanf("%d", &units);

    if (units <= 0) {
        printf("Invalid input! Units must be greater than 0.\n");
    } else if (units <= 100) {
        total_bill = units * 5.0;
    } else if (units <= 200) {
        total_bill = (100 * 5.0) + ((units - 100) * 7.0);
    } else {
        total_bill = (100 * 5.0) + (100 * 7.0) + ((units - 200) * 10.0);
    }

    if (units > 0) {
        printf("\n-----------------------------------\n");
        printf("Total Units Consumed: %d\n", units);
        printf("Total Payable Amount: Rs. %.2f\n", total_bill);
        printf("-----------------------------------\n");
    }

    return 0;
}