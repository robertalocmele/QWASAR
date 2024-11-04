#include <stdio.h>
#include <stdlib.h>

void my_square(int width, int height) {
    if (width <= 0 || height <= 0) {
        return;
    }

    // Print the top row
    printf("o");
    for (int i = 0; i < width - 2; i++) {
        printf("-");
    }
    if (width > 1) {
        printf("o");
    }
    printf("\n");

    // Print the middle rows
    for (int j = 0; j < height - 2; j++) {
        printf("|");
        for (int i = 0; i < width - 2; i++) {
            printf(" ");
        }
        if (width > 1) {
            printf("|");
        }
        printf("\n");
    }

    // Print the bottom row
    if (height > 1) {
        printf("o");
        for (int i = 0; i < width - 2; i++) {
            printf("-");
        }
        if (width > 1) {
            printf("o");
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    // Ensure there are exactly 3 arguments: program name, width, and height
    if (argc != 3) {
        return 0;  // Exit without printing anything
    }

    int width = atoi(argv[1]);
    int height = atoi(argv[2]);

    // Call the my_square function with the input width and height
    my_square(width, height);

    return 0;
}
