#include "copy_vec.h"
#include <stdio.h>

int main(void) {
    int vec1[] = {10, 20, 30};
    int vec2[3];

    copy_vec(vec1, 3, vec2);

    printf("vec2 = {%d, %d, %d}\n", *(vec2), *(vec2 + 1), *(vec2 + 2));
    return 0;
}
