#include <stdio.h>
#include <stdlib.h> 
#include <time.h>   

int main() {
    srand(time(0)); 
    
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
