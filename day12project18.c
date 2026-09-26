#include <stdio.h>

int main() {
    int item_choice, quantity;
    float price = 0.0, subtotal = 0.0, total_bill = 0.0;
    float discount = 0.0, tax, final_bill;
    int coupon_code;
    char add_more;

    printf("========================================\n");
    printf("     WELCOME TO APNA RESTAURANT        \n");
    printf("========================================\n");

    do {
        printf("\nMenu:\n");
        printf("1. Burger        - Rs. 120.00\n");
        printf("2. Pizza         - Rs. 250.00\n");
        printf("3. Pasta         - Rs. 150.00\n");
        printf("4. Cold Coffee   - Rs. 80.00\n");
        printf("5. Biryani       - Rs. 200.00\n");
        printf("----------------------------------------\n");

        printf("Enter Item Number (1-5): ");
        scanf("%d", &item_choice);

        printf("Enter Quantity: ");
        scanf("%d", &quantity);

        if (item_choice == 1) {
            price = 120.0;
        } else if (item_choice == 2) {
            price = 250.0;
        } else if (item_choice == 3) {
            price = 150.0;
        } else if (item_choice == 4) {
            price = 80.0;
        } else if (item_choice == 5) {
            price = 200.0;
        } else {
            printf("Invalid Choice! Skipping this item.\n");
            price = 0.0;
        }

        subtotal = price * quantity;
        total_bill += subtotal;

        printf("\nDo you want to order more items? (y/n): ");
        scanf(" %c", &add_more); 

    } while (add_more == 'y' || add_more == 'Y');

    printf("\nDo you have a Coupon Code?\n");
    printf("Enter Coupon Code (Enter 0 if none): ");
    scanf("%d", &coupon_code);

    if (coupon_code == 786) {
        discount = total_bill * 0.10; 
        printf("Coupon Applied Successfully! 10%% Discount added.\n");
    } else if (coupon_code != 0) {
        printf("Invalid Coupon Code! No discount applied.\n");
    }

    float amount_after_discount = total_bill - discount;
    tax = amount_after_discount * 0.18; 
    final_bill = amount_after_discount + tax;

    printf("\n========================================\n");
    printf("             FINAL BILL RECEIPT         \n");
    printf("========================================\n");
    printf("Total Items Bill      : Rs. %.2f\n", total_bill);
    printf("Discount              : Rs. %.2f\n", discount);
    printf("GST (18%%)              : Rs. %.2f\n", tax);
    printf("----------------------------------------\n");
    printf("TOTAL AMOUNT PAYABLE  : Rs. %.2f\n", final_bill);
    printf("========================================\n");

    return 0;
}