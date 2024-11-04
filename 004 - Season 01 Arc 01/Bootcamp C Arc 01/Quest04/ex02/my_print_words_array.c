#include <unistd.h> // For write function

#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array {
    int size;
    char** array;
} string_array;
#endif

void my_putstr(char* str) {
    while (*str) {
        write(1, str++, 1); // Print one character at a time
    }
}

void my_print_words_array(string_array* param_1) {
    for (int i = 0; i < param_1->size; i++) {
        my_putstr(param_1->array[i]); // Print each string
        write(1, "\n", 1); // New line after each word
    }
}
