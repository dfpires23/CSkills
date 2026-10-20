#include "sum_matrix_values.h"
#include <stdio.h>

int main(void) {
    int mat[5][3] = {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}, {13, 14, 15}};

    printf("%d\n", sum_matrix_values(mat));
    return 0;
}
