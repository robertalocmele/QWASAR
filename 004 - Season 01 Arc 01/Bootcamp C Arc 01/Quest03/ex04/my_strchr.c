#include <stdio.h>

char* my_strchr(char* param_1, char param_2) {
    int i = 0;

    // Loop through the string until the null terminator '\0' is reached
    while (param_1[i] != '\0') {
        // Check if the current character matches param_2
        if (param_1[i] == param_2) {
            // Return the pointer to the first occurrence of param_2
            return &param_1[i];
        }
        i++; // Move to the next character in the string
    }

    // If the character is not found, return NULL
    return NULL;
}

int main() {
    // Example inputs
    char *str = "abcabc";
    char ch = 'b';

    // Call my_strchr and store the result
    char *result = my_strchr(str, ch);

    // Check if result is NULL or a valid pointer
    if (result != NULL) {
        printf("Found character: %s\n", result); // Print from the first occurrence
    } else {
        printf("Character not found.\n");
    }

    return 0;
}
