#include "trim_string.h"
#include <stdio.h>

int main(void) {
    char str[] = "     the     numBERr     must be  saved     ";

    trim_string(str);
    printf("%s\n", str);

    return 0;
}
