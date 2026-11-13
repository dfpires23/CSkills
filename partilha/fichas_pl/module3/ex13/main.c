#include "asm.h"
#include <stdio.h>

int main(void) {
    int vec[] = {10, -50, 25, -60, 80, 12};

    keep_positives(vec, 6);

    printf("vec = {");
    for (int i = 0; i < 6; i++) {
        printf("%d", vec[i]);
        if (i < 5) {
            printf(", ");
        }
    }
    printf("}\n");

    return 0;
}
