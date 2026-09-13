#include <stdio.h>
#include <stdlib.h> // rand() aur srand() ke liye
#include <time.h>   // time() ke liye

int main() {
    // Har baar naya random number generate karne ke liye seed
    srand(time(0)); 
    
    // 1 se 100 ke beech random number generate karega
    int secret_number = (rand() % 100) + 1; 
    int guess;
    int attempts = 0;

    printf("=== Day 3: Guess The Secret Number Game ===\n");
    printf("I have picked a secret number between 1 and 100. Can you guess it?\n\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess > secret_number) {
            printf("Too High! Try a smaller number.\n\n");
        } else if (guess < secret_number) {
            printf("Too Low! Try a larger number.\n\n");
        } else {
            printf("\n*** Congratulations! You guessed the correct number %d in %d attempts! ***\n", secret_number, attempts);
        }
    } while (guess != secret_number);

    return 0;
}