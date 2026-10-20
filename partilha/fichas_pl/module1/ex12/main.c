#include "array_sort.h"
#include <stdio.h>

int main(void) {
    int vec[] = {5, 2, 8, 1, 3};

    array_sort(vec, 5);

    for (int i = 0; i < 5; i++) {
        printf("%d ", *(vec + i));
    }

    printf("\n");
    return 0;
}
