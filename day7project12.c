#include <stdio.h>

int main() {
    int choice;
    int book_id, days_late;
    float fine = 0.0;
    int max_allowed_days = 14;

    while (1) {
        printf("\n==========================================\n");
        printf("    LIBRARY FINE & RETURN TRACKER        \n");
        printf("==========================================\n");
        printf("1. Return Book & Calculate Fine\n");
        printf("2. Check Fine Rules & Policy\n");
        printf("3. Exit System\n");
        printf("------------------------------------------\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        if (choice == 3) {
            printf("\nExiting Library System. Happy Reading!\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("\nEnter Book ID (4-digit number): ");
                scanf("%d", &book_id);
                printf("Enter total days since book was issued: ");
                scanf("%d", &days_late);

                if (days_late <= max_allowed_days) {
                    printf("\n>> Success: Returned on time! No fine charged.\n");
                } else {
                    int extra_days = days_late - max_allowed_days;
                    
                    // Progressive Fine Logic
                    if (extra_days <= 5) {
                        fine = extra_days * 2.0; // Rs. 2/day for first 5 days late
                    } else if (extra_days <= 10) {
                        fine = (5 * 2.0) + ((extra_days - 5) * 5.0); // Rs. 5/day next 5 days
                    } else {
                        fine = (5 * 2.0) + (5 * 5.0) + ((extra_days - 10) * 10.0); // Rs. 10/day after 10 days
                    }

                    printf("\n------------ FINE INVOICE ------------\n");
                    printf("Book ID       : %d\n", book_id);
                    printf("Allowed Days  : %d days\n", max_allowed_days);
                    printf("Late Days     : %d days\n", extra_days);
                    printf("Total Fine    : Rs. %.2f\n", fine);
                    printf("--------------------------------------\n");
                }
                break;

            case 2:
                printf("\n-------------- FINE POLICY --------------\n");
                printf("Standard Return Limit : 14 Days\n");
                printf("Late Fee Slabs:\n");
                printf("  * 1 - 5 Days Late   : Rs. 2.00 / day\n");
                printf("  * 6 - 10 Days Late  : Rs. 5.00 / day\n");
                printf("  * > 10 Days Late    : Rs. 10.00 / day\n");
                printf("-----------------------------------------\n");
                break;

            default:
                printf("\n[Error] Invalid choice! Please select 1, 2, or 3.\n");
        }
    }

    return 0;
}