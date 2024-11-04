#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "game_logic.h"

// Function to generate a random code
void generateRandomCode(int codeArray[]) {
    srand(time(NULL)); // Seed the random generator
    for (int i = 0; i < 4; i++) {
        codeArray[i] = rand() % 9; // Generate digits between 0 and 8
    }
}

// Function to get the guess from the user
void getGuess(int guessArray[]) {
    char input[5];
    read(0, input, 5); // Read 4 characters + newline
    for (int i = 0; i < 4; i++) {
        guessArray[i] = input[i] - '0'; // Convert char to int
    }
}

// Function to compare the user's guess with the secret code
int compareCode(int codeArray[], int guessArray[]) {
    int correctPositions = 0;
    int misplaced = 0;
    int codeUsed[4] = {0}, guessUsed[4] = {0};

    // First pass: Check for well-placed pieces
    for (int i = 0; i < 4; i++) {
        if (codeArray[i] == guessArray[i]) {
            correctPositions++;
            codeUsed[i] = 1;
            guessUsed[i] = 1;
        }
    }

    // Second pass: Check for misplaced pieces
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (!codeUsed[j] && !guessUsed[i] && codeArray[j] == guessArray[i]) {
                misplaced++;
                codeUsed[j] = 1;
                guessUsed[i] = 1;
                break;
            }
        }
    }

    printf("Well placed pieces: %d, Misplaced pieces: %d\n", correctPositions, misplaced);
    return correctPositions;
}

// Utility function to print the secret code
void printCode(int codeArray[]) {
    for (int i = 0; i < 4; i++) {
        printf("%d", codeArray[i]);
    }
    printf("\n");
}
