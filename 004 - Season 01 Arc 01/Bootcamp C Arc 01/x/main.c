#include <stdio.h>
#include <stdlib.h>
#include "game_logic.h" // Include the header file for game functions

#define DEFAULT_ATTEMPTS 10 // Default number of attempts allowed

int main(int argc, char **argv) {
    int secretCode[4], userGuess[4];
    int attempts = DEFAULT_ATTEMPTS; // Initialize number of attempts
    int win = 0; // Variable to check if the user has won

    // Process command-line arguments to set attempts and secret code
    for (int i = 1; i < argc; i++) {
        if (argv[i][1] == 't') {
            attempts = atoi(argv[i + 1]); // Set number of attempts from argument
        }
        if (argv[i][1] == 'c') {
            for (int j = 0; j < 4; j++) {
                secretCode[j] = argv[i + 1][j] - '0'; // Set custom secret code
            }
        }
    }

    printf("Welcome to MASTERMIND\n");
    printf("Will you find the secret code?\n");

    // Generate a random code if no custom code is provided
    if (argc < 3 || argv[1][1] != 'c') {
        generateRandomCode(secretCode);
    }

    // Start the game loop for the specified number of attempts
    for (int round = 0; round < attempts; round++) {
        printf("---\nRound %d\n", round + 1); // Display current round
        printf("Enter your guess (4 digits from 0 to 8): \n");
        
        getGuess(userGuess); // Get the user's guess

        // Validate the user's guess
        if (!isValidGuess(userGuess)) {
            printf("Please enter a valid guess (4 digits between 0 and 8)\n");
            round--; // Invalid input, repeat the same round
            continue;
        }

        win = compareCode(secretCode, userGuess); // Compare guess with secret code

        // Check if the user has won
        if (win == 4) {
            printf("Congratz! You did it!\n");
            break;
        }

        // Check if the user has run out of attempts
        if (round == attempts - 1) {
            printf("You've run out of attempts! The code was: ");
            printCode(secretCode); // Display the secret code
        }
    }

    return 0; // Exit the program
}
