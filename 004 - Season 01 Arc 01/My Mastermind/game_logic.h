#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

void generateRandomCode(int secretCode[]); 
void getGuess(int userGuess[]); 
int compareCode(int secretCode[], int userGuess[]); 
void printCode(int secretCode[]); 
int isValidGuess(int userGuess[]); 

#endif
