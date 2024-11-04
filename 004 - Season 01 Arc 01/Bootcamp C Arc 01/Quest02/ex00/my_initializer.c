#include <stdio.h>

void my_initializer(int *pointer) {
    *pointer = 0;
}

int main() {
    int x = 5;
    printf("Before: %d\n", x);  // Output: Before: 5
    
    my_initializer(&x);          // Pass the address of x to the function
    printf("After: %d\n", x);    // Output: After: 0
    
    return 0;
}

/* 
#include <stdio.h>

// Function that takes a pointer to an integer and sets the value to 0
void initialize_to_zero(int *ptr) {
    *ptr = 0;  // Dereference the pointer and set the value to 0
}

int main() {
    int num = 10;  // Declare an integer variable
    printf("Before: %d\n", num);
    
    // Call the function with the address of num
    initialize_to_zero(&num);
    
    printf("After: %d\n", num);  // The value of num should now be 0
    return 0;
}
*/