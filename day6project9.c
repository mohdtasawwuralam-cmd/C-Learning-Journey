#include <stdio.h>

int main() {
    int vehicle_type;
    int age;
    char gender;
    float distance = 0.0;
    float rate_per_km = 0.0;
    float base_fare = 0.0;
    float discount = 0.0;
    float final_fare = 0.0;

    printf("===========================================\n");
    printf("   SMART FARE & SCHEME DISCOUNT SYSTEM     \n");
    printf("===========================================\n");

    // Step 1: Vehicle Selection (Bus is cheapest)
    printf("Select Vehicle Type:\n");
    printf("1. City Bus            -> RS 2/km (Cheapest)\n");
    printf("2. Two-Wheeler (Bike)   -> RS 5/km\n");
    printf("3. Car / Auto / Cab    -> RS 12/km\n");
    printf("Enter choice (1-3): ");
    scanf("%d", &vehicle_type);

    if (vehicle_type < 1 || vehicle_type > 3) {
        printf("\n[ERROR] Invalid Vehicle Selection!\n");
        return 0;
    }

    // Step 2: Distance Input
    printf("\nEnter total travel distance (in KM): ");
    scanf("%f", &distance);

    if (distance <= 0) {
        printf("\n[ERROR] Distance must be greater than 0!\n");
        return 0;
    }

    // Step 3: Passenger Demographics (Age & Gender)
    printf("\nEnter Age: ");
    scanf("%d", &age);

    printf("Enter Gender (M for Male, F for Female): ");
    scanf(" %c", &gender); // %c se pehle space space leak handle karta hai

    // ------------------- LOGIC SECTION -------------------

    // Rate set karna vehicle ke hisab se
    if (vehicle_type == 1) {
        rate_per_km = 2.0;  // Bus (Per passenger rate)
    } else if (vehicle_type == 2) {
        rate_per_km = 5.0;  // Bike
    } else if (vehicle_type == 3) {
        rate_per_km = 12.0; // Car
    }

    base_fare = distance * rate_per_km;

    // Discount Calculation Rules
    if ((gender == 'F' || gender == 'f') && vehicle_type == 1) {
        // Rule 1: Females ke liye Bus bilkul FREE
        discount = 1.0; // 100% discount
        printf("\n[SCHEME APPLIED] Pink Ticket: Free Travel for Females in Bus!\n");
    } 
    else if (age >= 60) {
        // Rule 2: Senior Citizen Discount (50%)
        discount = 0.50;
        printf("\n[SCHEME APPLIED] Senior Citizen Special: 50%% Off!\n");
    } 
    else if ((gender == 'M' || gender == 'm') && age < 18) {
        // Rule 3: Boys under 18 get 30% Discount
        discount = 0.30;
        printf("\n[SCHEME APPLIED] Student/Minor Discount: 30%% Off!\n");
    } 
    else {
        discount = 0.0; // Normal Fare
    }

    // Final Fare Calculation
    final_fare = base_fare - (base_fare * discount);

    // ------------------- RECEIPT SECTION -------------------

    printf("\n-------------------------------------------\n");
    printf("              TICKET RECEIPT               \n");
    printf("-------------------------------------------\n");
    printf("Vehicle Category : %s\n", 
            (vehicle_type == 1) ? "City Bus" : 
            (vehicle_type == 2) ? "Bike" : "Car/Cab");
            
    printf("Distance         : %.2f KM\n", distance);
    printf("Passenger Info   : Age %d | Gender %c\n", age, gender);
    printf("Base Ticket Price: INR %.2f\n", base_fare);
    printf("Discount Applied : %.0f%%\n", discount * 100);
    printf("-------------------------------------------\n");
    printf("FINAL AMOUNT DUE : INR %.2f\n", final_fare);
    printf("-------------------------------------------\n");

    return 0;
}