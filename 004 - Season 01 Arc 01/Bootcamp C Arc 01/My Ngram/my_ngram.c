#include <stdio.h>
#define MAX_ARRAY_SIZE 128

// Function to fill the array with character counts from a string
void fill_array(int* array, char* str) {
    int index = 0;

    // Loop through the string until the null terminator is found
    while (str[index] != '\0') {
        if (str[index] != '"') {  // Ignore double quotes
            array[(int)str[index]] += 1;  // Increment the count for the character
        }
        index += 1;
    }   
}

// Function to print the character counts
void print_array(int* array, int size_array) {
    int index = 0;

    // Loop through the array and print non-zero counts
    while (index < size_array) {
         if (array[index] > 0) {
             printf("%c:%d\n", index, array[index]);  // Print character and its count without spaces
         }
         index += 1;
    }
}

int main(int argc, char **argv) {
    int index = 1;  // Start at the first argument (skip program name)
    int array[MAX_ARRAY_SIZE] = {0};  // Initialize array to store character counts

    // Process each argument (string) passed to the program
    while (index < argc) {
        fill_array(array, argv[index]);  // Count characters in the string
        index += 1;
    }

    // Print the results
    print_array(array, MAX_ARRAY_SIZE);
    return 0;
}
