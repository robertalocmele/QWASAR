char* my_downcase(char* param_1) {
    int i = 0;

    // Loop through the string until the null terminator '\0'
    while (param_1[i] != '\0') {
        // Convert uppercase letters to lowercase manually
        if (param_1[i] >= 'A' && param_1[i] <= 'Z') {
            param_1[i] = param_1[i] - 'A' + 'a';
        }
        i++;
    }

    // Return the modified string
    return param_1;
}
