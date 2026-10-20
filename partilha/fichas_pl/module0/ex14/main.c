#include "count_value.h"
#include <stdio.h>

int main(void) {
    int v[] = {1, 2, 3, 3, 3};

    printf("%d\n", count_value(v, 5, 3));
    return 0;
}
