#include "asm.h"
#include <stdio.h>

int main(void) {
    char str1[] = "Hello ";
    char str2[] = "World!";
    char str3[81];

    str_cat(str1, str2, str3);
    printf("str3 = %s\n", str3);

    return 0;
}
