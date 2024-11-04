#include <stdio.h>
#include "game_logic.h" // Include the header file for prototypes

// Function to validate if the guess is correct (digits between 0 and 8)
int isValidGuess(int userGuess[]) {
    for (int i = 0; i < 4; i++) {
        if (userGuess[i] < 0 || userGuess[i] > 8) { // Check if digit is in valid range
            return 0; // Invalid guess
        }
    }
    return 1; // Valid guess
}
