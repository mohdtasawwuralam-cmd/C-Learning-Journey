#include <stdio.h>

int main() {
    int item_choice;
    int quantity;
    
    // Inventory Stock
    int laptop_stock = 3;
    int phone_stock = 0; // Out of stock item to test 'continue'
    int headphone_stock = 5;

    // Prices in INR
    double laptop_price = 45000.0;
    double phone_price = 15000.0;
    double headphone_price = 1500.0;

    double total_sales_revenue = 0.0;

    printf("==================================================\n");
    printf("   E-COMMERCE FLASH SALE & ORDER MANAGER (DAY 8)  \n");
    printf("==================================================\n\n");

    while (1) {
        printf("--- Available Items in Flash Sale ---\n");
        printf("1. Laptop     | Price: Rs. %.2f | Stock: %d\n", laptop_price, laptop_stock);
        printf("2. Smartphone | Price: Rs. %.2f | Stock: %d (OUT OF STOCK)\n", phone_price, phone_stock);
        printf("3. Headphones | Price: Rs. %.2f | Stock: %d\n", headphone_price, headphone_stock);
        printf("0. Close Store & Generate Daily Report\n");
        printf("Select product to purchase (0-3): ");
        scanf("%d", &item_choice);

        // REAL USE-CASE OF BREAK: Store Manager closes sale session manually
        if (item_choice == 0) {
            printf("\n>> Closing Flash Sale System...\n");
            break; 
        }

        // REAL USE-CASE OF CONTINUE: Out of stock item selection handling
        if (item_choice == 2) {
            printf("\n>> [REJECTED] Smartphone is OUT OF STOCK! Please select another item.\n\n");
            continue; // Order processing code skip karke catalog par wapas bhejo
        }

        // Invalid Option Handling
        if (item_choice < 0 || item_choice > 3) {
            printf("\n>> [ERROR] Invalid Selection! Try again.\n\n");
            continue;
        }

        // Quantity Input
        printf("Enter Quantity: ");
        scanf("%d", &quantity);

        if (quantity <= 0) {
            printf("\n>> [ERROR] Quantity must be greater than 0!\n\n");
            continue;
        }

        // Stock & Order Validation
        if (item_choice == 1) {
            if (quantity > laptop_stock) {
                printf("\n>> [FAILED] Not enough stock! Available: %d\n\n", laptop_stock);
                continue;
            }
            laptop_stock -= quantity;
            total_sales_revenue += (quantity * laptop_price);
            printf("\n>> [SUCCESS] Order Placed! %d Laptop(s) booked.\n\n", quantity);
        } 
        else if (item_choice == 3) {
            if (quantity > headphone_stock) {
                printf("\n>> [FAILED] Not enough stock! Available: %d\n\n", headphone_stock);
                continue;
            }
            headphone_stock -= quantity;
            total_sales_revenue += (quantity * headphone_price);
            printf("\n>> [SUCCESS] Order Placed! %d Headphone(s) booked.\n\n", quantity);
        }

        // Auto Break Check: Agar Laptop aur Headphones bhi out of stock ho jayein
        if (laptop_stock == 0 && headphone_stock == 0) {
            printf(">> [ALERT] ALL ITEMS ARE SOLD OUT! Ending Flash Sale automatically.\n");
            break;
        }
    }

    // Final Sales Summary
    printf("\n==================================================\n");
    printf("               DAILY SALES SUMMARY                \n");
    printf("==================================================\n");
    printf("Total Revenue Generated : Rs. %.2f\n", total_sales_revenue);
    printf("Remaining Laptop Stock  : %d\n", laptop_stock);
    printf("Remaining Headphone Stock: %d\n", headphone_stock);
    printf("==================================================\n");

    return 0;
}