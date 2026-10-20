#include "average.h"
#include <stdio.h>

int main(void) {
    int v[] = {1, 2};
    int r = 0;

    r = average(v[0], v[1]);

    printf("average =%d\n", r);
    printf("average array =%d\n", average_array(v, 2));
    return 0;
}
