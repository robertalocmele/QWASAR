#include <stdlib.h>

int* my_range(int param_1, int param_2) {
    if (param_1 >= param_2) {
        return NULL; // Return null pointer if min >= max
    }

    int size = param_2 - param_1;
    int* array = malloc(size * sizeof(int));
    if (!array) {
        return NULL; // Handle memory allocation failure
    }

    for (int i = 0; i < size; i++) {
        array[i] = param_1 + i; // Fill the array
    }

    return array; // Return the pointer to the array
}
