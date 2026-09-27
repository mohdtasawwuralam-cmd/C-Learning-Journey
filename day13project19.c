#include <stdio.h>

int main() {
    int route_choice, coach_choice, passenger_age, category_choice, is_tatkal;
    int student_id;
    char college_name[50];
    
    float base_fare = 0.0;
    float discount = 0.0, tatkal_charge = 0.0, final_fare;

    printf("========================================\n");
    printf("     INDIAN RAILWAY RESERVATION SYSTEM  \n");
    printf("========================================\n");

    // Step 1: Select Route
    printf("Select Route:\n");
    printf("1. Delhi to Mumbai\n");
    printf("2. Delhi to Chennai\n");
    printf("3. Delhi to Kolkata\n");
    printf("4. Delhi to Bengaluru\n");
    printf("Enter Route Choice (1-4): ");
    scanf("%d", &route_choice);

    if (route_choice < 1 || route_choice > 4) {
        printf("\nInvalid Route Choice! Program Terminated.\n");
        return 0;
    }

    // Step 2: Select Dibba (Coach Class) with Specific Rates
    printf("\nSelect Coach Class (Dibba):\n");
    printf("1. VIP / 1st AC Class (1A)  - Executive VIP\n");
    printf("2. 2nd AC Class (2A)        - Premium AC\n");
    printf("3. 3rd AC Class (3A)        - Economy AC\n");
    printf("4. Sleeper Class (SL)       - Non-AC General\n");
    printf("Enter Class Choice (1-4): ");
    scanf("%d", &coach_choice);

    // Route + Dibba Price Calculation
    if (route_choice == 1) { // Delhi to Mumbai
        if (coach_choice == 1) base_fare = 3000.0;      // VIP 1st AC
        else if (coach_choice == 2) base_fare = 2000.0; // 2nd AC
        else if (coach_choice == 3) base_fare = 1400.0; // 3rd AC
        else if (coach_choice == 4) base_fare = 500.0;  // Sleeper
    } 
    else if (route_choice == 2) { // Delhi to Chennai
        if (coach_choice == 1) base_fare = 3800.0;
        else if (coach_choice == 2) base_fare = 2500.0;
        else if (coach_choice == 3) base_fare = 1800.0;
        else if (coach_choice == 4) base_fare = 700.0;
    } 
    else if (route_choice == 3) { // Delhi to Kolkata
        if (coach_choice == 1) base_fare = 3400.0;
        else if (coach_choice == 2) base_fare = 2200.0;
        else if (coach_choice == 3) base_fare = 1600.0;
        else if (coach_choice == 4) base_fare = 600.0;
    } 
    else if (route_choice == 4) { // Delhi to Bengaluru
        if (coach_choice == 1) base_fare = 4200.0;
        else if (coach_choice == 2) base_fare = 2800.0;
        else if (coach_choice == 3) base_fare = 2000.0;
        else if (coach_choice == 4) base_fare = 800.0;
    }

    if (base_fare == 0.0) {
        printf("\nInvalid Class Choice! Program Terminated.\n");
        return 0;
    }

    // Step 3: Passenger Age Input
    printf("\nEnter Passenger Age: ");
    scanf("%d", &passenger_age);

    if (passenger_age <= 0 || passenger_age > 110) {
        printf("\nInvalid Age! Program Terminated.\n");
        return 0;
    }

    // Step 4: Category Verification (Senior Citizen / Student Verification)
    if (passenger_age >= 60) {
        discount = base_fare * 0.40; // 40% Senior Citizen Discount
        printf("\n--> Senior Citizen Concession (40%%) applied!\n");
    } else {
        printf("\nSelect Passenger Category:\n");
        printf("1. General Passenger\n");
        printf("2. Student (Requires College ID Verification)\n");
        printf("Enter Category Choice (1 or 2): ");
        scanf("%d", &category_choice);

        if (category_choice == 2) {
            printf("\nEnter College Name (Single-word, e.g. JMI): ");
            scanf("%s", college_name);

            printf("Enter Student Roll/ID Number: ");
            scanf("%d", &student_id);

            discount = base_fare * 0.25; // 25% Student Discount
            printf("\n[VERIFIED] College: %s | Student ID: %d\n", college_name, student_id);
            printf("--> Student Concession (25%%) applied successfully!\n");
        } else {
            printf("\n--> General Category selected.\n");
        }
    }

    // Step 5: Tatkal Surcharge
    printf("\nIs this a Tatkal Booking?\n");
    printf("Enter 1 for Tatkal (Rs. 200 Surcharge), 0 for Normal: ");
    scanf("%d", &is_tatkal);

    if (is_tatkal == 1) {
        tatkal_charge = 200.00;
    }

    // Step 6: Final Ticket Calculation
    final_fare = (base_fare - discount) + tatkal_charge;

    // Step 7: Print Final Receipt
    printf("\n========================================\n");
    printf("          CONFIRMED TRAIN TICKET        \n");
    printf("========================================\n");
    printf("Base Fare (Selected Dibba) : Rs. %.2f\n", base_fare);
    printf("Concession Discount        : -Rs. %.2f\n", discount);
    printf("Tatkal Surcharge           : +Rs. %.2f\n", tatkal_charge);
    printf("----------------------------------------\n");
    printf("TOTAL FARE PAYABLE         : Rs. %.2f\n", final_fare);
    printf("========================================\n");

    return 0;
}