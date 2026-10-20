#include "get_parts.h"
#include <stdio.h>

int main(void) {
    char str[] = "123.456";

    printf("Integer: %d\n", integer_part(str));
    printf("Fractional: %d\n", fractional_part(str));
    return 0;
}
