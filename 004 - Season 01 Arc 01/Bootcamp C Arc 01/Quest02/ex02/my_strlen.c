#include <stddef.h>  // Include this header for size_t

size_t my_strlen(const char *s) {
    size_t length = 0;        // Initialize length to 0

    // Iterate through the string until we encounter the null terminator '\0'
    while (s[length] != '\0') {
        length++;
    }

    return length;            // Return the number of characters
}
