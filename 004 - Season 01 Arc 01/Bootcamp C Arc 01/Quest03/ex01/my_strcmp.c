#include <stdio.h>

int my_strcmp(char* param_1, char* param_2) {
    int i = 0;

    while (param_1[i] != '\0' && param_2[i] != '\0') {
        if (param_1[i] != param_2[i]) {
            if (param_1[i] < param_2[i]) {
                return -1;
            } else {
                return 1;
            }
        }
        i++;
    }

    if (param_1[i] == '\0' && param_2[i] == '\0') {
        return 0;
    } else if (param_1[i] == '\0') {
        return -1;
    } else {
        return 1;
    }
}

int main() {
    char str1[] = "abc";
    char str2[] = "bd";
    char str3[] = "abc";
    char str4[] = "ab";

    printf("Comparing \"%s\" and \"%s\": %d\n", str1, str2, my_strcmp(str1, str2));
    printf("Comparing \"%s\" and \"%s\": %d\n", str2, str1, my_strcmp(str2, str1));
    printf("Comparing \"%s\" and \"%s\": %d\n", str1, str3, my_strcmp(str1, str3));
    printf("Comparing \"%s\" and \"%s\": %d\n", str1, str4, my_strcmp(str1, str4));

    return 0;
}
