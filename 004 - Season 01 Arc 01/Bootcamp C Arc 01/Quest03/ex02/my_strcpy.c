#include <stdio.h>

char* my_strcpy(char* param_1, char* param_2) {
    int i = 0;

    while (param_2[i] != '\0') {
        param_1[i] = param_2[i]; 
        i++; 
    }
    param_1[i] = '\0';
    return param_1;
}

int main() {
    // Create a destination buffer that is large enough to hold the source string
    char dst[100]; // 100 characters should be enough space for most examples

    // Define a source string that we want to copy
    char *src = "Hello World!";

    // Call the my_strcpy function to copy src into dst
    my_strcpy(dst, src);

    // Print the destination string to see the result
    printf("Copied string: %s\n", dst);

    return 0;
}
