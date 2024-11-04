/*
Create a my_string_formatting function which takes 3 parameters (firstname, lastname and age) and prints a string composed value.

Formatting should be: "Hello, my name is FIRSTNAME LASTNAME, I'm AGE."

Make sure you are printing a newline.
*/

#include <stdio.h>

void my_string_formatting(char* param_1, char* param_2, int param_3) {
    // Print the formatted string using printf
    printf("Hello, my name is %s %s, I'm %d.\n", param_1, param_2, param_3);
}
