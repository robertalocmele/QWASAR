#include <unistd.h>
#include <stdarg.h>
#include <string.h>

// Function to print a character
int print_char(char c) {
    return write(1, &c, 1);
}

// Function to print a string
int print_string(char *str) {
    if (str == NULL) {
        return write(1, "(null)", 6);
    }
    return write(1, str, strlen(str));
}

// Function to print an integer
int print_int(int num) {
    int count = 0;
    if (num < 0) {
        count += print_char('-');
        num = -num;
    }
    if (num / 10) {
        count += print_int(num / 10);
    }
    count += print_char((num % 10) + '0');
    return count;
}

// Function to print an unsigned integer
int print_unsigned(unsigned int num) {
    int count = 0;
    if (num / 10) {
        count += print_unsigned(num / 10);
    }
    count += print_char((num % 10) + '0');
    return count;
}

// Function to print octal numbers
int print_octal(unsigned int num) {
    char buffer[11]; 
    int num_digits = 0;

    if (num == 0) {
        return write(1, "0", 1);
    }

    // Convert the number to octal
    while (num > 0) {
        buffer[num_digits++] = (num % 8) + '0'; // octal digit
        num /= 8; 
    }

    // Print in reverse order
    for (int j = num_digits - 1; j >= 0; j--) {
        write(1, &buffer[j], 1);
    }

    return num_digits; // return total length
}

// Function to print hexadecimal numbers
int print_hex(unsigned long num, int uppercase) {
    char buffer[16];  
    int num_digits = 0;

    if (num == 0) {
        return write(1, "0", 1);
    }

    // Convert the number to hexadecimal
    while (num > 0) {
        int digit = num % 16;
        if (digit < 10) {
            buffer[num_digits++] = (digit + '0');  // 0-9
        } else {
            buffer[num_digits++] = (uppercase ? (digit - 10 + 'A') : (digit - 10 + 'a'));  // a-f or A-F
        }
        num /= 16;
    }

    // Print in reverse order
    for (int j = num_digits - 1; j >= 0; j--) {
        write(1, &buffer[j], 1);
    }

    return num_digits;  // Return total length
}

// Function to print pointer addresses
int print_pointer(void *ptr) {
    unsigned long address = (unsigned long)ptr;  
    int count = 0;

    count += write(1, "0x", 2);
    count += print_hex(address, 0); 

    return count; 
}

// Custom printf function
int my_printf(const char *format, ...) {
    va_list args;
    int total_count = 0;

    va_start(args, format);
    for (const char *p = format; *p != '\0'; p++) {
        if (*p == '%') {
            p++;  // Move to the next character
            switch (*p) {
                case 'c':
                    total_count += print_char(va_arg(args, int));
                    break;
                case 's':
                    total_count += print_string(va_arg(args, char *));
                    break;
                case 'd':
                    total_count += print_int(va_arg(args, int));
                    break;
                case 'u':
                    total_count += print_unsigned(va_arg(args, unsigned int));
                    break;
                case 'o':
                    total_count += print_octal(va_arg(args, unsigned int));  // octal
                    break;
                case 'x':
                    total_count += print_hex(va_arg(args, unsigned int), 0);  // lowercase
                    break;
                case 'X':
                    total_count += print_hex(va_arg(args, unsigned int), 1);  // uppercase
                    break;
                case 'p':
                    total_count += print_pointer(va_arg(args, void *));
                    break;
                default:
                    total_count += print_char(*p);
                    break;
            }
        } else {
            total_count += print_char(*p);
        }
    }
    va_end(args);
    return total_count;  // Return the total number of characters printed
}