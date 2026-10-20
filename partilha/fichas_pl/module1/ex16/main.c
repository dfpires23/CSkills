#include "format_word.h"
#include <stdio.h>

int main(void) {
    char str[] = "hello, world!";

    format_word(str);
    printf("%s\n", str);

    return 0;
}
