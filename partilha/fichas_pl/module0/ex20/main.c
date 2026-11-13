#include "check_lower_triangular_matrix.h"
#include "sum_lower_triangular_matrix.h"
#include <stdio.h>

int main() {

    int mat[3][5] = {{1, 0, 0, 0, 0}, {4, 5, 0, 0, 0}, {7, 8, 9, 0, 0}};

    printf("Lower triangular: %d\n", check_lower_triangular_matrix(mat, 3, 5));

    printf("Sum: %d\n", sum_lower_triangular_matrix(mat, 3));

    return 0;
}