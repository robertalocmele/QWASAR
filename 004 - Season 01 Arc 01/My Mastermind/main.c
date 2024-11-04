#include <stdio.h>
#include <stdlib.h>
#include "game_logic.h"

#define DEFAULT_ATTEMPTS 10 

// Function to check if the provided secret code has duplicates
int hasDuplicates(int secretCode[]) {
    int seen[9] = {0};  // Array to track seen digits from 0 to 8
    for (int i = 0; i < 4; i++) {
        if (seen[secretCode[i]]) {
            return 1;  // Duplicate found
        }
        seen[secretCode[i]] = 1; // Mark this digit as seen
    }
    return 0; // No duplicates
}

// Function to validate if all digits in the code are between 0 and 8
int isValidSecretCode(int secretCode[]) {
    for (int i = 0; i < 4; i++) {
        if (secretCode[i] < 0 || secretCode[i] > 8) {
            return 0;  // Invalid digit found
        }
    }
    return 1;  // All digits are valid
}

int main(int argc, char **argv) {
    int secretCode[4], userGuess[4];
    int attempts = DEFAULT_ATTEMPTS; 
    int win = 0; 

    for (int i = 1; i < argc; i++) {
        if (argv[i][1] == 't') {
            attempts = atoi(argv[i + 1]); 
        }
        if (argv[i][1] == 'c') {
            for (int j = 0; j < 4; j++) {
                secretCode[j] = argv[i + 1][j] - '0'; 
            }

            // Check if the secret code has duplicates
            if (hasDuplicates(secretCode)) {
                printf("Invalid secret code. Please provide a 4-digit code with no duplicates.\n");
                return 1; // Exit with error
            }

            // Check if all digits are between 0 and 8
            if (!isValidSecretCode(secretCode)) {
                printf("Invalid secret code. All digits must be between 0 and 8.\n");
                return 1; // Exit with error
            }
        }
    }

    printf("Welcome to MASTERMIND\n");
    printf("Will you find the secret code?\n");

    if (argc < 3 || argv[1][1] != 'c') {
        generateRandomCode(secretCode);
    }

    for (int round = 0; round < attempts; round++) {
        printf("---\nRound %d\n", round + 1); 

        getGuess(userGuess);  // The prompt inside getGuess will handle the message

        if (!isValidGuess(userGuess)) {
            printf("Please enter a valid guess\n");  // Match the message expected by the test
            round--; 
            continue;
        }


        win = compareCode(secretCode, userGuess); 

        if (win == 4) {
            printf("Congratz! You did it!\n");
            break;
        }

        if (round == attempts - 1) {
            printf("You've run out of attempts! The code was: ");
            printCode(secretCode); 
        }
    }

    return 0; 
}
