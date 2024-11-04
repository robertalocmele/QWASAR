#include <stdio.h>
#include <stdlib.h>
#include "game_logic.h" // Include the header file to access functions

#define DEFAULT_ATTEMPTS 10

int main(int argc, char **argv) {
    int codeArray[4], guessArray[4];
    int tries = DEFAULT_ATTEMPTS;
    int win = 0;

    // Handle command-line arguments
    for (int i = 1; i < argc - 1; i++) {
        if (argv[i][1] == 't') {
            tries = atoi(argv[i + 1]); // Set number of attempts
        }
        if (argv[i][1] == 'c') {
            for (int j = 0; j < 4; j++) {
                codeArray[j] = argv[i + 1][j] - '0'; // Set custom code
            }
        }
    }

    printf("Welcome to MASTERMIND\n");
    printf("Will you find the secret code?\n");

    if (argc < 3 || argv[1][1] != 'c') {
        generateRandomCode(codeArray); // Generate random code if no custom code
    }

    // Start the game loop
    for (int round = 0; round < tries; round++) {
        printf("---\nRound %d\n", round);
        printf("Enter your guess: \n");

        getGuess(guessArray); // Get user guess

        if (!isValidGuess(guessArray)) {
            printf("Please enter a valid guess (4 digits between 0 and 8)\n");
            round--; // Invalid input, repeat the same round
            continue;
        }

        win = compareCode(codeArray, guessArray); // Compare guess with the secret code

        if (win == 4) {
            printf("Congratz! You did it!\n");
            break;
        }

        if (round == tries - 1) {
            printf("You've run out of attempts! The code was: ");
            printCode(codeArray);
        }
    }

    return 0;
}
