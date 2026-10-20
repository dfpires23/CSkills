#include "where_is.h"
#include <stdio.h>

int main(void) {
    char str[] = "Hello, World!";
    char c = 'W';
    char *ptr = where_is(str, c);

    printf("%p\n", ptr);
    return 0;
}
