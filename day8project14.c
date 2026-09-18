#include <stdio.h>

int main() {
    int vehicle_type;
    int emergency_flag;
    int total_vehicles = 0;
    int vip_pass_count = 0;
    double total_collection = 0.0;

    // Toll Rates
    double car_rate = 100.0;
    double bus_truck_rate = 250.0;
    double bike_rate = 30.0;

    printf("==================================================\n");
    printf("   SMART HIGHWAY TOLL PLAZA SYSTEM (DAY 8)       \n");
    printf("==================================================\n\n");

    while (1) {
        printf("--- Vehicle Entry Gate ---\n");
        printf("1. Two Wheeler (Bike/Scooter) - Rs. %.2f\n", bike_rate);
        printf("2. Light Vehicle (Car/Jeep)    - Rs. %.2f\n", car_rate);
        printf("3. Heavy Vehicle (Bus/Truck)   - Rs. %.2f\n", bus_truck_rate);
        printf("0. Close Shift & Generate Toll Report\n");
        printf("Select Vehicle Type (0-3): ");
        scanf("%d", &vehicle_type);

        // REAL USE-CASE OF BREAK: Shift Supervisor closes operations
        if (vehicle_type == 0) {
            printf("\n>> Shift Closed By Supervisor. Processing Summary...\n");
            break; 
        }

        // Invalid Choice Check
        if (vehicle_type < 0 || vehicle_type > 3) {
            printf("\n>> [ERROR] Invalid Selection! Try again.\n\n");
            continue; // Invalid entry skip karke wapas menu par bhejo
        }

        // Emergency / VIP Check
        printf("Is it an Emergency/VIP Vehicle? (1 for Yes, 0 for No): ");
        scanf("%d", &emergency_flag);

        // REAL USE-CASE OF CONTINUE: Skip payment calculation for Emergency
        if (emergency_flag == 1) {
            printf(">> [EXEMPTED] Emergency/VIP Vehicle Detected! Toll Gate Opened (FREE PASS).\n\n");
            vip_pass_count++;
            total_vehicles++;
            continue; // Payment addition block skip karo aur next vehicle process karo
        }

        // Billing Logic
        total_vehicles++;
        if (vehicle_type == 1) {
            total_collection += bike_rate;
            printf(">> [SUCCESS] Bike Toll Collected: Rs. %.2f\n\n", bike_rate);
        } else if (vehicle_type == 2) {
            total_collection += car_rate;
            printf(">> [SUCCESS] Car Toll Collected: Rs. %.2f\n\n", car_rate);
        } else if (vehicle_type == 3) {
            total_collection += bus_truck_rate;
            printf(">> [SUCCESS] Heavy Vehicle Toll Collected: Rs. %.2f\n\n", bus_truck_rate);
        }
    }

    // Shift Financial Summary Report
    printf("\n==================================================\n");
    printf("             SHIFT COLLECTION REPORT              \n");
    printf("==================================================\n");
    printf("Total Vehicles Passed : %d\n", total_vehicles);
    printf("VIP / Exempted Vehicles: %d\n", vip_pass_count);
    printf("Paid Transactions     : %d\n", total_vehicles - vip_pass_count);
    printf("Total Cash Collected  : Rs. %.2f\n", total_collection);
    printf("==================================================\n");

    return 0;
}