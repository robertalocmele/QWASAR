/*Create a my_string_index function which takes 2 parameters (haystack and needle) and locates the first occurrence of the character needle in the string haystack and returns the position.

You can think of this function as: is there an L (character) in my string "helLo"?

The objective is to build a loop that has an if statement which returns the characters position when it matches the right character.
*/

int my_string_index(char* param_1, char param_2) {
    int i = 0;

    // Loop through the string until the null terminator '\0'
    while (param_1[i] != '\0') {
        // Check if the current character matches the needle (param_2)
        if (param_1[i] == param_2) {
            return i;  // Return the index of the first occurrence
        }
        i++;
    }

    // If the character is not found, return -1
    return -1;
}
