#include "asm.h"
#include <stdio.h>

int main() {
    int values[] = {2, 5, 3, 4, 8, 6, 1};
    int num = 7;

    int result = count_max(values, num);

    printf("%d\n", result);

    return 0;
}
