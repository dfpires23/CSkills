#include "check_string.h"
#include <stdio.h>

int main(void) {
    char str[] = "I will master ARQCP";

    printf("%d\n", check_string(str, 1636));
    return 0;
}
