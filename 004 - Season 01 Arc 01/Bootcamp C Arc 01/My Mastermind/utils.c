#include <stdio.h>
#include "game_logic.h"

// Function to validate if the guess is correct (digits between 0 and 8)
int isValidGuess(int guessArray[]) {
    for (int i = 0; i < 4; i++) {
        if (guessArray[i] < 0 || guessArray[i] > 8) {
            return 0; // Invalid guess
        }
    }
    return 1; // Valid guess
}
