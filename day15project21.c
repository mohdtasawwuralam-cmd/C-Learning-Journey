#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BankAccount {
    int acc_number;
    char name[50];
    int pin;
    float balance;
};

void createAccount();
void displayAccount();
void depositMoney();

int main() {
    int choice;

    while (1) {
        printf("\n==========================================\n");
        printf("    ADVANCED FILE-BASED BANK SYSTEM       \n");
        printf("==========================================\n");
        printf("1. Create New Account\n");
        printf("2. Display Account Details\n");
        printf("3. Deposit Money\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            break;
        }

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                displayAccount();
                break;
            case 3:
                depositMoney();
                break;
            case 4:
                printf("\nExiting System. Data saved safely!\n");
                return 0;
            default:
                printf("\nInvalid Choice! Try again.\n");
        }
    }
    return 0;
}

// 1. CREATE ACCOUNT (Proper File Writing)
void createAccount() {
    FILE *fp = fopen("accounts.txt", "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    struct BankAccount acc;

    printf("\nEnter Account Number: ");
    scanf("%d", &acc.acc_number);
    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]s", acc.name);
    printf("Set 4-Digit Security PIN: ");
    scanf("%d", &acc.pin);
    printf("Enter Initial Deposit Amount: ");
    scanf("%f", &acc.balance);

    // Save with precise formatting
    fprintf(fp, "%d,%s,%d,%.2f\n", acc.acc_number, acc.name, acc.pin, acc.balance);
    fclose(fp);

    printf("\nAccount Created & Saved to File Successfully!\n");
}

// 2. DISPLAY ACCOUNT (Proper File Reading)
void displayAccount() {
    FILE *fp = fopen("accounts.txt", "r");
    if (fp == NULL) {
        printf("\nNo account database found. Create an account first!\n");
        return;
    }

    int search_acc, entered_pin;
    int found = 0;
    struct BankAccount acc;

    printf("\nEnter Account Number: ");
    scanf("%d", &search_acc);
    printf("Enter PIN: ");
    scanf("%d", &entered_pin);

    // Read comma-separated values safely
    while (fscanf(fp, "%d,%49[^,],%d,%f\n", &acc.acc_number, acc.name, &acc.pin, &acc.balance) == 4) {
        if (acc.acc_number == search_acc && acc.pin == entered_pin) {
            printf("\n========== ACCOUNT DETAILS ==========\n");
            printf("Account No : %d\n", acc.acc_number);
            printf("Holder Name: %s\n", acc.name);
            printf("Balance    : Rs %.2f\n", acc.balance);
            printf("=====================================\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nInvalid Account Number or PIN!\n");
    }

    fclose(fp);
}

// 3. DEPOSIT MONEY (Safe Temp File Updating)
void depositMoney() {
    FILE *fp = fopen("accounts.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (fp == NULL || temp == NULL) {
        printf("\nDatabase error or file not found!\n");
        if (fp) fclose(fp);
        if (temp) fclose(temp);
        return;
    }

    int search_acc, entered_pin;
    float amount;
    int found = 0;
    struct BankAccount acc;

    printf("\nEnter Account Number: ");
    scanf("%d", &search_acc);
    printf("Enter PIN: ");
    scanf("%d", &entered_pin);

    while (fscanf(fp, "%d,%49[^,],%d,%f\n", &acc.acc_number, acc.name, &acc.pin, &acc.balance) == 4) {
        if (acc.acc_number == search_acc && acc.pin == entered_pin) {
            printf("Enter Deposit Amount: ");
            scanf("%f", &amount);
            if (amount > 0) {
                acc.balance += amount;
                printf("Deposit Successful! New Balance: Rs %.2f\n", acc.balance);
            } else {
                printf("Invalid Amount!\n");
            }
            found = 1;
        }
        // Write back to temp file
        fprintf(temp, "%d,%s,%d,%.2f\n", acc.acc_number, acc.name, acc.pin, acc.balance);
    }

    fclose(fp);
    fclose(temp);

    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");

    if (!found) {
        printf("\nInvalid Account Number or PIN!\n");
    }
}