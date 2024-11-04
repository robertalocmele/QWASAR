#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

// Function prototypes
void generateRandomCode(int secretCode[]); // Generates a random secret code
void getGuess(int userGuess[]); // Gets a guess from the user
int compareCode(int secretCode[], int userGuess[]); // Compares guess to secret code
void printCode(int secretCode[]); // Prints the secret code
int isValidGuess(int userGuess[]); // Validates the user's guess

#endif // GAME_LOGIC_H
