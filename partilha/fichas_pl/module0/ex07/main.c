#include "get_ascii_code.h"
#include <stdio.h>

int main(void) {
    char c;
    scanf("%c", &c);

    printf("%d\n", get_ascii_code(c));
    return 0;
}
