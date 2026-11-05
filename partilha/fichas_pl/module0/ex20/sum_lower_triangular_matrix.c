#include "check_lower_triangular_matrix.h"

int sum_lower_triangular_matrix(int mat[][5], int lin) {

    if (check_lower_triangular_matrix(mat, lin, 5) == 0) {
        return -1;
    }

    int sum = 0;

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < 5; j++) {
            sum += mat[i][j];
        }
    }

    return sum;
}