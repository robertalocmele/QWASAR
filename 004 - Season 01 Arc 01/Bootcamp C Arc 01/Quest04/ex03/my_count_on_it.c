#include <stdlib.h>

#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array {
    int size;
    char** array;
} string_array;
#endif

#ifndef STRUCT_INTEGER_ARRAY
#define STRUCT_INTEGER_ARRAY
typedef struct s_integer_array {
    int size;
    int* array;
} integer_array;
#endif

integer_array* my_count_on_it(string_array* param_1) {
    integer_array* result = malloc(sizeof(integer_array));
    if (!result) {
        return NULL; // Handle memory allocation failure
    }

    result->size = param_1->size;
    result->array = malloc(result->size * sizeof(int));
    if (!result->array) {
        free(result); // Clean up
        return NULL; // Handle memory allocation failure
    }

    for (int i = 0; i < param_1->size; i++) {
        int length = 0;
        while (param_1->array[i][length] != '\0') {
            length++; // Calculate length of each string
        }
        result->array[i] = length; // Store length
    }

    return result; // Return the pointer to the integer array
}
