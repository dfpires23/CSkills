#include "sort_without_reps.h"
#include <stdio.h>

int main(void) {
    short int vec1[] = {2, 1, 3, 2, 3, 4, 5, 1};
    short int vec2[8];
    int count = sort_without_reps(vec1, 8, vec2);

    for (int i = 0; i < count; i++) {
        printf("%d ", *(vec2 + i));
    }

    printf("\n");
    printf("Count=%d\n", count);

    return 0;
}