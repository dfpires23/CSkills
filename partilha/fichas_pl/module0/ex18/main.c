#include "find_pattern.h"
#include <stdio.h>

int main(void) {
    char str[] = "ola Pedro, ola Laura";
    char patt[] = "la";

    printf("%d\n", find_pattern(str, patt));
    return 0;
}
