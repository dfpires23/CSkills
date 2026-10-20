#include "get_array_statistics.h"
#include <stdio.h>

int main(void) {
    int vec[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int min = 0, max = 0;
    float avg = 0.0;

    get_array_statistics(vec, 9, &min, &max, &avg);

    printf("Min:%d, Max:%d, Avg:%.2f\n", min, max, avg);
    return 0;
}
