void get_array_statistics(int *vec, int n, int *min, int *max, float *avg) {
    if (n <= 0) {
        *min = 0;
        *max = 0;
        *avg = 0.0f;
        return;
    }

    int d_min = *vec;
    int d_max = *vec;
    int d_sum = 0;

    for (int i = 0; i < n; i++) {
        if (*(vec + i) < d_min) {
            d_min = *(vec + i);
        }
        if (*(vec + i) > d_max) {
            d_max = *(vec + i);
        }
        d_sum += *(vec + i);
    }

    *min = d_min;
    *max = d_max;
    *avg = (float)d_sum / n;
}
