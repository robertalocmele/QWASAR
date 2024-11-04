#include <stdio.h>

char* my_strncpy(char* param_1, char* param_2, int param_3) {
    int i = 0;

    while (i < param_3 && param_2[i] != '\0') {
        param_1[i] = param_2[i]; 
        i++; 
    }
    while (i < param_3) {
        param_1[i] = '\0'; // Fill the remaining space with null characters
        i++;
    }
    return param_1;
}

int main() {
    char dst[100]; 

    char *src = "HelloWorld!";

    // Define how many characters need to be copied (6 characters in this case)
    int hm = 6;

    // Call the my_strncpy function to copy src into dst
    my_strncpy(dst, src, hm);

    // Print the destination string to see the result
    printf("Copied string: %s\n", dst);

    return 0;
}
