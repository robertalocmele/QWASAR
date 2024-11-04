#include <stdlib.h>

char* my_strdup(char* param_1) {
    if (!param_1) {
        return NULL; // Handle NULL input
    }

    int length = 0;
    while (param_1[length] != '\0') {
        length++; // Calculate length of the string
    }

    char* copy = malloc((length + 1) * sizeof(char));
    if (!copy) {
        return NULL; // Handle memory allocation failure
    }

    for (int i = 0; i < length; i++) {
        copy[i] = param_1[i]; // Copy each character
    }
    copy[length] = '\0'; // Null-terminate the new string

    return copy; // Return the pointer to the copied string
}
