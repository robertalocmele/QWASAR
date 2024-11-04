/*
Description
You have been recently been hired by SpacePro, a new rocket manufacturer, and have been tasked with designing a simulator for their spaceships. This simulator creates a virtual “space” and keeps track of the basic movements and direction of a given ship. Your job is to keep track of where the ship is and it’s orientation relative to its starting point.

Instructions
Your ship simulator must take in a string of letters that represent a planned flight path for a given rocket ship.

In a ship’s flight path there are only 3 valid options for movement; R for turning right, L for turning left and A for advancing.

If, for example, you receive “RRALAA” as your flight path, you should interpret it as the following:
Turn right, turn right, advance, turn left, advance, advance
Once given this initial flight path, your program must return the x,y coordinates of a ship’s final destination as well as it’s orientation relative to the starting point.

Orientation is represented as left, right, up or down.

Space is infinite, so the x,y coordinates you return could be placed on a seemingly infinite grid and can be negative or positive values.

So let's say an upward-facing rocket ship leaves its starting point of 0,0 and is given the flight path of “RRALAA”, its final location will be 2,-1 and it will be facing right.

Your Job
You must create a function that takes in a flight path of a rocket ship as a string of letters and returns the following format:
"{x: X, y: Y, direction: 'DIRECTION'}"
X,Y represent the ending coordinates of your ship and direction represents its final direction.

Notes
Function myspaceship returns a _STRING.
*/
#include <stdlib.h>
#include <stdio.h>

char* my_spaceship(char* param_1) {
    int x = 0, y = 0;
    char* directions[] = {"up", "right", "down", "left"};
    int direction = 0; // Start facing up

    for (int i = 0; param_1[i] != '\0'; i++) {
        if (param_1[i] == 'R') {
            direction = (direction + 1) % 4; // Turn right
        } else if (param_1[i] == 'L') {
            direction = (direction + 3) % 4; // Turn left
        } else if (param_1[i] == 'A') {
            if (direction == 0) y--; // Move up
            else if (direction == 1) x++; // Move right
            else if (direction == 2) y++; // Move down
            else if (direction == 3) x--; // Move left
        }
    }

    char* result = malloc(100); // Allocate memory for the result
    snprintf(result, 100, "{x: %d, y: %d, direction: '%s'}", x, y, directions[direction]);
    return result; // Return the final position and direction
}
