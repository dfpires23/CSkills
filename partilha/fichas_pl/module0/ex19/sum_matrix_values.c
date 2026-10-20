int sum_matrix_values(int mat[5][3]) {
    int sum = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            sum += mat[i][j];
        }
    }

    return sum;
}
