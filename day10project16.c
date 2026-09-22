#include <stdio.h>

int main() {
    int vehicleType;
    float hours, baseCharge = 0.0, surcharge = 0.0, totalAmount = 0.0;

    printf("=== PARKING TOLL SYSTEM ===\n");
    printf("1. Two-Wheeler (Bike)\n");
    printf("2. Four-Wheeler (Car)\n");
    printf("3. Bus / Heavy Vehicle\n");
    printf("Select Vehicle Type (1-3): ");
    scanf("%d", &vehicleType);

    // Invalid vehicle type check
    if (vehicleType < 1 || vehicleType > 3) {
        printf("\nError: Invalid vehicle type selected!\n");
        return 1;
    }

    printf("Enter parking duration (in hours): ");
    scanf("%f", &hours);

    if (hours <= 0) {
        printf("\nError: Invalid duration entered!\n");
        return 1;
    }

    // Base charge calculation based on vehicle type
    switch (vehicleType) {
        case 1: // Two-Wheeler
            if (hours <= 2) {
                baseCharge = 20.0;
            } else {
                baseCharge = 20.0 + (hours - 2) * 10.0;
            }
            break;

        case 2: // Four-Wheeler
            if (hours <= 2) {
                baseCharge = 50.0;
            } else {
                baseCharge = 50.0 + (hours - 2) * 20.0;
            }
            break;

        case 3: // Bus / Heavy Vehicle
            baseCharge = hours * 100.0;
            break;
    }

    // 20% Surcharge for duration > 12 hours
    if (hours > 12) {
        surcharge = baseCharge * 0.20;
    }

    totalAmount = baseCharge + surcharge;

    // Ticket Receipt Output
    printf("\n--- PARKING TICKET RECEIPT ---\n");
    if (vehicleType == 1) {
        printf("Vehicle Type    : Two-Wheeler\n");
    } else if (vehicleType == 2) {
        printf("Vehicle Type    : Four-Wheeler\n");
    } else {
        printf("Vehicle Type    : Bus / Heavy Vehicle\n");
    }

    printf("Total Hours     : %.1f hrs\n", hours);
    printf("Base Charge     : Rs. %.2f\n", baseCharge);
    
    if (surcharge > 0) {
        printf("Night Surcharge : Rs. %.2f (20%% for >12 hrs)\n", surcharge);
    } else {
        printf("Night Surcharge : Rs. 0.00\n");
    }
    
    printf("-------------------------------\n");
    printf("Total Amount    : Rs. %.2f\n", totalAmount);

    return 0;
}