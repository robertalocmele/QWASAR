#include <stdio.h>

#ifndef STRUCT_INTEGER_ARRAY
#define STRUCT_INTEGER_ARRAY
typedef struct s_integer_array
{
    int size;
    int* array;
} integer_array;
#endif

void my_first_struct(integer_array* param_1)
{
    // Check if the size of the array is 0
    if (param_1->size == 0) {
        printf("0\n");
        return;
    }

    // Print the size of the array
    printf("%d\n", param_1->size);

    // Iterate through the array and print each element
    for (int i = 0; i < param_1->size; i++) {
        printf("%d\n", param_1->array[i]);
    }
}
