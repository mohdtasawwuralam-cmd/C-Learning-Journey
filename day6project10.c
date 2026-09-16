#include <stdio.h>

int main() {
    int seat_type;
    int show_time;
    int age;
    char add_popcorn;
    float ticket_price = 0.0;
    float popcorn_price = 0.0;
    float total_bill = 0.0;

    printf("===========================================\n");
    printf("     PVR MULTIPLEX SMART TICKET SYSTEM     \n");
    printf("===========================================\n");

    // Step 1: Age Verification (A-Rated Movie Check)
    printf("Enter Viewer Age: ");
    scanf("%d", &age);

    if (age < 18) {
        printf("\n[ENTRY RESTRICTED] Sorry, this movie is A-Rated (18+ Only)!\n");
        return 0; // Minor entry blocked
    }

    // Step 2: Seat Selection
    printf("\nSelect Seat Category:\n");
    printf("1. Silver   (RS 150)\n");
    printf("2. Gold     (RS 250)\n");
    printf("3. Platinum (RS 400)\n");
    printf("Enter choice (1-3): ");
    scanf("%d", &seat_type);

    if (seat_type < 1 || seat_type > 3) {
        printf("\n[ERROR] Invalid Seat Choice!\n");
        return 0;
    }

    // Step 3: Show Timing Selection
    printf("\nSelect Show Timing:\n");
    printf("1. Morning Show   (20%% Flat Discount)\n");
    printf("2. Regular Show   (Standard Rate)\n");
    printf("3. Night Prime    (15%% Surge Charge)\n");
    printf("Enter choice (1-3): ");
    scanf("%d", &show_time);

    if (show_time < 1 || show_time > 3) {
        printf("\n[ERROR] Invalid Timing Choice!\n");
        return 0;
    }

    // Step 4: Optional Snack Combo
    printf("\nDo you want to add a Large Popcorn Combo for RS 180? (Y/N): ");
    scanf(" %c", &add_popcorn);

    // ------------------- LOGIC SECTION -------------------

    // Base Seat Price Setting
    if (seat_type == 1) {
        ticket_price = 150.0;
    } else if (seat_type == 2) {
        ticket_price = 250.0;
    } else if (seat_type == 3) {
        ticket_price = 400.0;
    }

    // Show Timing Adjustments
    if (show_time == 1) {
        ticket_price = ticket_price - (ticket_price * 0.20); // 20% Off
    } else if (show_time == 3) {
        ticket_price = ticket_price + (ticket_price * 0.15); // 15% Extra
    }

    // Popcorn Addition
    if (add_popcorn == 'Y' || add_popcorn == 'y') {
        popcorn_price = 180.0;
    }

    total_bill = ticket_price + popcorn_price;

    // ------------------- RECEIPT SECTION -------------------

    printf("\n-------------------------------------------\n");
    printf("              BOOKING SUMMARY              \n");
    printf("-------------------------------------------\n");
    printf("Viewer Status    : Verified (Age %d)\n", age);
    printf("Seat Category    : %s\n", 
            (seat_type == 1) ? "Silver" : 
            (seat_type == 2) ? "Gold" : "Platinum");

    printf("Show Shift       : %s\n", 
            (show_time == 1) ? "Morning (-20%%)" : 
            (show_time == 2) ? "Regular" : "Night (+15%%)");

    printf("Ticket Price     : INR %.2f\n", ticket_price);
    printf("Popcorn Combo    : INR %.2f\n", popcorn_price);
    printf("-------------------------------------------\n");
    printf("FINAL PAYABLE    : INR %.2f\n", total_bill);
    printf("-------------------------------------------\n");
    printf("        ENJOY YOUR MOVIE SHOW!             \n");
    printf("===========================================\n");

    return 0;
}