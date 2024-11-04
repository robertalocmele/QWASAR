#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check if the user provided at least one file as an argument
    if (argc < 2) {
        printf("Usage: %s <file1> <file2> ...\n", argv[0]);
        return 1;  // Return an error code
    }

    // Buffer to hold file data
    char buffer[1024];
    size_t bytesRead;

    // Loop through each file argument provided by the user
    for (int i = 1; i < argc; i++) {
        // Open the file in read mode
        FILE *file = fopen(argv[i], "r");

        // Check if the file was opened successfully
        if (file == NULL) {
            printf("Error: Could not open file %s\n", argv[i]);
            continue;  // Skip to the next file
        }

        // Read the file in chunks and print the contents to the terminal
        while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
            fwrite(buffer, 1, bytesRead, stdout);  // Print the buffer to stdout
        }

        // Close the file
        fclose(file);
    }

    return 0;  // Return 0 to indicate the program finished successfully
}

