#include "capitalize.h"
#include <stdio.h>

int main(void) {
    char str[] = "Hello, World!";

    capitalize(str);

    printf("%s\n", str);
    return 0;
}
