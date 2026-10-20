void compress(int *vec_ints, int n, long long *vec_longs) {
    int n_longs = n / 2;

    for (int i = 0; i < n_longs; i++) {
        int *temp = (int *)(vec_longs + i);
        int j = i * 2;

        *(temp + 0) = *(vec_ints + j);
        *(temp + 1) = *(vec_ints + j + 1);
    }
}
