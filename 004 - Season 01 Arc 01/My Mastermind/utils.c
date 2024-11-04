#include <stdio.h>
#include "game_logic.h"

int isValidGuess(int userGuess[]) {
    int seen[9] = {0};  // Array to track seen digits from 0 to 8

    for (int i = 0; i < 4; i++) {
        if (userGuess[i] < 0 || userGuess[i] > 8) { 
            return 0; // Invalid digit
        }
        if (seen[userGuess[i]]) {
            return 0; // Duplicate digit found
        }
        seen[userGuess[i]] = 1; // Mark this digit as seen
    }
    return 1; // Valid guess
}