#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

// Function prototypes
void generateRandomCode(int codeArray[]);
void getGuess(int guessArray[]);
int compareCode(int codeArray[], int guessArray[]);
void printCode(int codeArray[]);
int isValidGuess(int guessArray[]);

#endif
