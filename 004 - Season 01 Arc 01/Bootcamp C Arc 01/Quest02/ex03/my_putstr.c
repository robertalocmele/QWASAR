#include <unistd.h>  // Include for the write function

void my_putstr(char* param_1) {
    int i = 0;

    // Loop through the string until the null terminator '\0' is encountered
    while (param_1[i] != '\0') {
        write(1, &param_1[i], 1);  // Write one character to standard output
        i++;
    }
}
