/*
Create a my_upcase function that takes a string as a parameter and returns the uppercase version of it.
*/
#include <ctype.h>  // For the `toupper` function

char* my_upcase(char* param_1) {
    int i = 0;

    // Loop through the string until the null terminator '\0'
    while (param_1[i] != '\0') {
        // Convert lowercase letters to uppercase
        param_1[i] = toupper(param_1[i]);
        i++;
    }

    // Return the modified string
    return param_1;
}

