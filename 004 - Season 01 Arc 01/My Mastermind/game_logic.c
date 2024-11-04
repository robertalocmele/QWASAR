#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>  // Include this for strcspn and strlen
#include "game_logic.h" 

void generateRandomCode(int secretCode[]) {
    srand(time(NULL)); 
    for (int i = 0; i < 4; i++) {
        secretCode[i] = rand() % 9; 
    }
}

void getGuess(int userGuess[]) {
    char input[100];  // Larger buffer to handle user input

    while (1) {
        printf("Enter your code (4 digits from 0 to 8): \n"); // Updated message
        if (fgets(input, sizeof(input), stdin) != NULL) {
            // Remove the newline character if present
            input[strcspn(input, "\n")] = 0;

            // Check if the input length is exactly 4
            if (strlen(input) == 4) {
                int valid = 1; // Flag to check if the input is valid

                // Convert the input to the integer array
                for (int i = 0; i < 4; i++) {
                    if (input[i] < '0' || input[i] > '8') {
                        valid = 0;  // Mark as invalid
                        break;  // Break out of the loop since one digit is invalid
                    }
                    userGuess[i] = input[i] - '0';
                }

                // If the input is valid, return
                if (valid) {
                    return; // Exit the function once valid input is received.
                }
            } 
        } else {
            // Handle EOF (Ctrl + D) and exit
            printf("\nEOF detected. Exiting the game.\n");
            exit(0); // Exit the program
        }

        // If we reach here, the guess was invalid
        printf("Please enter a valid code (4 digits between 0 and 8)\n"); // Updated message
    }
}

int compareCode(int secretCode[], int userGuess[]) {
    int wellPlaced = 0; 
    int misplaced = 0; 
    int codeUsed[4] = {0}, guessUsed[4] = {0}; 

    // Count well-placed pieces
    for (int i = 0; i < 4; i++) {
        if (secretCode[i] == userGuess[i]) {
            wellPlaced++; 
            codeUsed[i] = 1; 
            guessUsed[i] = 1;
        }
    }

    // Count misplaced pieces
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (!codeUsed[j] && !guessUsed[i] && secretCode[j] == userGuess[i]) {
                misplaced++; 
                codeUsed[j] = 1; 
                guessUsed[i] = 1; 
                break;  // Move to next digit once a match is found
            }
        }
    }

    printf("Well placed pieces: %d, Misplaced pieces: %d\n", wellPlaced, misplaced);
    return wellPlaced;
}


void printCode(int secretCode[]) {
    for (int i = 0; i < 4; i++) {
        printf("%d", secretCode[i]); 
    }
    printf("\n"); 
}
