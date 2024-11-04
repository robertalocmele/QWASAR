#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "game_logic.h" // Include header for function prototypes

// Function to generate a random 4-digit secret code (digits 0-8)
void generateRandomCode(int secretCode[]) {
    srand(time(NULL)); // Seed random number generator
    for (int i = 0; i < 4; i++) {
        secretCode[i] = rand() % 9; // Assign a random digit between 0 and 8
    }
}

// Function to read the user's guess and convert to integers
void getGuess(int userGuess[]) {
    char input[5]; // Array to hold user input (4 digits + null terminator)
    read(0, input, 5); // Read 4 characters + newline
    for (int i = 0; i < 4; i++) {
        userGuess[i] = input[i] - '0'; // Convert character to integer
    }
}

// Function to compare the user's guess with the secret code
int compareCode(int secretCode[], int userGuess[]) {
    int wellPlaced = 0; // Count of correctly placed digits
    int misplaced = 0; // Count of misplaced digits
    int codeUsed[4] = {0}, guessUsed[4] = {0}; // Flags to track used digits

    // First pass: Check for well-placed pieces
    for (int i = 0; i < 4; i++) {
        if (secretCode[i] == userGuess[i]) {
            wellPlaced++; // Increment for correct position
            codeUsed[i] = 1; // Mark this digit as used in the code
            guessUsed[i] = 1; // Mark this digit as used in the guess
        }
    }

    // Second pass: Check for misplaced pieces
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            // Count misplaced if digits match and haven't been counted yet
            if (!codeUsed[j] && !guessUsed[i] && secretCode[j] == userGuess[i]) {
                misplaced++; // Increment misplaced count
                codeUsed[j] = 1; // Mark this digit as used in the code
                guessUsed[i] = 1; // Mark this digit as used in the guess
                break; // Exit inner loop to prevent double counting
            }
        }
    }

    // Print the results of the comparison
    printf("Well placed pieces: %d, Misplaced pieces: %d\n", wellPlaced, misplaced);
    return wellPlaced; // Return the count of well-placed pieces
}

// Utility function to print the secret code
void printCode(int secretCode[]) {
    for (int i = 0; i < 4; i++) {
        printf("%d", secretCode[i]); // Print each digit of the secret code
    }
    printf("\n"); // New line for readability
}
