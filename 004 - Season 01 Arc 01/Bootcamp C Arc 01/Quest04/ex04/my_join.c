#include <stdlib.h>

#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array {
    int size;
    char** array;
} string_array;
#endif

char* my_join(string_array* param_1, char* param_2) {
    if (param_1->size == 0) {
        return NULL; // Return NULL if the array is empty
    }

    int total_length = 0;
    for (int i = 0; i < param_1->size; i++) {
        int length = 0;
        while (param_1->array[i][length] != '\0') {
            length++; // Calculate total length of all strings
        }
        total_length += length;
    }

    total_length += (param_1->size - 1) * (param_2 ? strlen(param_2) : 0); // Add separator lengths

    char* result = malloc(total_length + 1); // +1 for null terminator
    if (!result) {
        return NULL; // Handle memory allocation failure
    }

    char* current = result;
    for (int i = 0; i < param_1->size; i++) {
        int j = 0;
        while (param_1->array[i][j] != '\0') {
            *current++ = param_1->array[i][j++]; // Copy each character
        }
        if (i < param_1->size - 1 && param_2) {
            int k = 0;
            while (param_2[k] != '\0') {
                *current++ = param_2[k++]; // Add separator
            }
        }
    }

    *current = '\0'; // Null-terminate the result
    return result; // Return the joined string
}
