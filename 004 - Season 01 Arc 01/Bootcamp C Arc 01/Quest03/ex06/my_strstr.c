#include <stdio.h>

char* my_strstr(char* param_1, char* param_2) {
    if (*param_2 == '\0') {
        return param_1;
    }
    for (int i = 0; param_1[i] != '\0'; i++) {
  
        int j = 0;
        while (param_2[j] != '\0' && param_1[i + j] == param_2[j]) {
            j++;
        }
        if (param_2[j] == '\0') {
            return &param_1[i]; 
        }
    }
    return NULL;
}

// Example main function to test the code
int main() {
    // Example 1: Haystack contains needle
    char *haystack1 = "hello";
    char *needle1 = "ll";
    char *result1 = my_strstr(haystack1, needle1);
    if (result1) {
        printf("Found substring: %s\n", result1); // Expected output: "llo"
    } else {
        printf("Substring not found.\n");
    }

    // Example 2: Haystack does not contain needle
    char *haystack2 = "aaaaa";
    char *needle2 = "bba";
    char *result2 = my_strstr(haystack2, needle2);
    if (result2) {
        printf("Found substring: %s\n", result2);
    } else {
        printf("Substring not found.\n"); // Expected output: "Substring not found."
    }

    // Example 3: Empty haystack or needle
    char *haystack3 = "";
    char *needle3 = "a";
    char *result3 = my_strstr(haystack3, needle3);
    if (result3) {
        printf("Found substring: %s\n", result3);
    } else {
        printf("Substring not found.\n"); // Expected output: "Substring not found."
    }

    return 0;
}
