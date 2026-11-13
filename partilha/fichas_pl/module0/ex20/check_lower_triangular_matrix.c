int check_lower_triangular_matrix(int mat[][5], int lin, int col) {

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {

            if (j > i && mat[i][j] != 0) {
                return 0;
            }
        }
    }

    return 1;
}