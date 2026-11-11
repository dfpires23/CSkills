#include "sort_without_reps.h"
#include <stdio.h>

int main(void) {
    short src[] = {5, 2, 8, 2, 1, 5, 3};
    short dest[7];

    int n = sort_without_reps(src, dest, 7);

    printf("Resultado: ");

    for (int i = 0; i < n; i++) {
        printf("%hd ", dest[i]);
    }

    printf("\nNumero de elementos: %d\n", n);

    return 0;
}