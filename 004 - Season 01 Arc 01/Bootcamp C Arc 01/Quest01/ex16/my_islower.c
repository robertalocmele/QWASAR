#include <stdio.h>

int my_islower(char param_1) {
    if (param_1 >= 'a' && param_1 <= 'z') {
        return 1;
    }
    return 0;
}
