#include <stdio.h>
#include <string.h>

struct Patient {
    int id;
    char name[50];
    int age;
    int roomType; // 1: General, 2: ICU
    int days;
    float totalBill;
};

int main() {
    struct Patient p[10];
    int count = 0, choice;

    do {
        printf("\n=========================================\n");
        printf("    HOSPITAL PATIENT MANAGEMENT SYSTEM   \n");
        printf("=========================================\n");
        printf("1. Register New Patient\n");
        printf("2. Display All Patients & Bills\n");
        printf("3. View Critical ICU Patients\n");
        printf("4. Exit\n");
        printf("Enter Choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (count < 10) {
                    printf("\n--- Patient %d Registration ---\n", count + 1);
                    printf("Enter Patient ID: ");
                    scanf("%d", &p[count].id);

                    printf("Enter Name: ");
                    scanf(" %[^\n]s", p[count].name);

                    printf("Enter Age: ");
                    scanf("%d", &p[count].age);

                    printf("Select Room (1 = General Ward [Rs 1000/day], 2 = ICU [Rs 3500/day]): ");
                    scanf("%d", &p[count].roomType);

                    printf("Enter Days Admitted: ");
                    scanf("%d", &p[count].days);

                    // Bill calculation logic
                    if (p[count].roomType == 1) {
                        p[count].totalBill = p[count].days * 1000.0;
                    } else if (p[count].roomType == 2) {
                        p[count].totalBill = p[count].days * 3500.0;
                    } else {
                        printf("Invalid Room Selection! Defaulting to General Ward.\n");
                        p[count].roomType = 1;
                        p[count].totalBill = p[count].days * 1000.0;
                    }

                    count++;
                    printf("Patient Registered Successfully!\n");
                } else {
                    printf("Hospital Bed Limit Reached (Max 10)!\n");
                }
                break;

            case 2:
                if (count == 0) {
                    printf("\nNo Patient Records Available!\n");
                } else {
                    printf("\n----------------------------------------------------------------------\n");
                    printf("ID\tName\t\tAge\tRoom\t\tDays\tTotal Bill\n");
                    printf("----------------------------------------------------------------------\n");
                    for (int i = 0; i < count; i++) {
                        printf("%d\t%-12s\t%d\t%s\t%d\t₹%.2f\n",
                               p[i].id,
                               p[i].name,
                               p[i].age,
                               (p[i].roomType == 2) ? "ICU" : "General",
                               p[i].days,
                               p[i].totalBill);
                    }
                    printf("----------------------------------------------------------------------\n");
                }
                break;

            case 3:
                printf("\n--- CRITICAL ICU PATIENTS LIST ---\n");
                int icuFound = 0;
                for (int i = 0; i < count; i++) {
                    if (p[i].roomType == 2) {
                        printf("ID: %d | Name: %s | Days in ICU: %d\n", p[i].id, p[i].name, p[i].days);
                        icuFound = 1;
                    }
                }
                if (!icuFound) {
                    printf("No patients currently in ICU.\n");
                }
                break;

            case 4:
                printf("\nExiting System. Take care!\n");
                break;

            default:
                printf("Invalid Choice! Please enter 1-4.\n");
        }
    } while (choice != 4);

    return 0;
}