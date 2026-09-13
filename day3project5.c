#include <stdio.h>
#include <windows.h> // Windows delay function ke liye

int main() {
    int total_seconds;

    printf("=== Day 3: Digital Timer Simulation ===\n\n");
    printf("Enter countdown timer in seconds: ");
    scanf("%d", &total_seconds);

    if (total_seconds <= 0) {
        printf("Please enter a valid time greater than 0.\n");
        return 1;
    }

    printf("\nStarting Timer...\n");

    while (total_seconds > 0) {
        int minutes = total_seconds / 60;
        int seconds = total_seconds % 60;

        printf("\rTime Remaining: %02d:%02d", minutes, seconds);
        fflush(stdout);

        Sleep(1000); // 1000 milliseconds = 1 second delay
        total_seconds--;
    }

    printf("\n\nTIME'S UP! Timer Finished.\n");

    return 0;
}