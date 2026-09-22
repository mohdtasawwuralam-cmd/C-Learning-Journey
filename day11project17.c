#include <stdio.h>
#include <string.h>

int main() {
    char message[100];
    int key, choice;

    while (1) {
        printf("\n====================================\n");
        printf("    SECRET MESSAGE ENCRYPTER        \n");
        printf("====================================\n");
        printf("1. Encrypt Message (Encode)\n");
        printf("2. Decrypt Message (Decode)\n");
        printf("3. Exit\n");
        printf("Select Choice (1-3): ");
        scanf("%d", &choice);

        if (choice == 3) {
            printf("\nProgram closed successfully!\n");
            break;
        }

        // Buffer clean karne ke liye taaki newline characters problem na karein
        getchar();

        if (choice == 1) {
            printf("\nEnter Secret Message (Text): ");
            fgets(message, sizeof(message), stdin);
            
            // Trailing newline character remove karna
            message[strcspn(message, "\n")] = 0;

            printf("Enter Secret Key / Shift Number (1-10): ");
            scanf("%d", &key);

            // Encryption Logic: Har character ki ASCII value shift karna
            for (int i = 0; message[i] != '\0'; i++) {
                if (message[i] >= 'a' && message[i] <= 'z') {
                    message[i] = (message[i] - 'a' + key) % 26 + 'a';
                } else if (message[i] >= 'A' && message[i] <= 'Z') {
                    message[i] = (message[i] - 'A' + key) % 26 + 'A';
                }
            }

            printf("\n[ENCRYPTED RESULT]: %s\n", message);
        } 
        else if (choice == 2) {
            printf("\nEnter Encrypted Text to Decode: ");
            fgets(message, sizeof(message), stdin);
            message[strcspn(message, "\n")] = 0;

            printf("Enter Key used for Encryption: ");
            scanf("%d", &key);

            // Decryption Logic: ASCII value ko waapis shift back karna
            for (int i = 0; message[i] != '\0'; i++) {
                if (message[i] >= 'a' && message[i] <= 'z') {
                    message[i] = (message[i] - 'a' - key + 26) % 26 + 'a';
                } else if (message[i] >= 'A' && message[i] <= 'Z') {
                    message[i] = (message[i] - 'A' - key + 26) % 26 + 'A';
                }
            }

            printf("\n[DECRYPTED RESULT]: %s\n", message);
        } 
        else {
            printf("\nInvalid Option! Try again.\n");
        }
    }

    return 0;
}