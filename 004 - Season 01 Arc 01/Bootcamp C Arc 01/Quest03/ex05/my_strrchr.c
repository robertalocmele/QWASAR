#include <stdio.h>

char* my_strrchr(char* param_1, char param_2) {
    char* last_occurrence = NULL;

    for (int i = 0; param_1[i] != '\0'; i++) {
        if (param_1[i] == param_2) {
            last_occurrence = &param_1[i];
        }
    }
    if (param_2 == '\0') {
        return &param_1[0];
    }
    return last_occurrence;
}

int main() {
    // Example input
    char *str = "abcabc";
    char ch = 'b';

    // Call the function and print the result
    char *result = my_strrchr(str, ch);

    if (result != NULL) {
        printf("Last occurrence: %s\n", result);
    } else {
        printf("Character not found.\n");
    }

    return 0;
}
