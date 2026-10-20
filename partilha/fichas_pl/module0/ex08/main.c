#include "get_ascii_char.h"
#include <stdio.h>

int main(void) {
    int d;
    scanf("%d", &d);

    printf("%c\n", get_ascii_char(d));
    return 0;
}
