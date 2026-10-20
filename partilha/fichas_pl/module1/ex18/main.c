#include "functions.h"
#include <stdio.h>

int main(void) {
    unsigned char vec[50];

    populate(vec, 50, 21);
    for (int i = 0; i < 50 - 2; i++) {
        if (check(*(vec + i), *(vec + i + 1), *(vec + i + 2)))
            inc_nsets();
    }

    printf("%d\n", nbr_of_sets);

    return 0;
}
