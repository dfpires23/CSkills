void frequencies(float *grades, int n, int *freq) {
    for (int i = 0; i < n; i++) {
        int temp = *(grades + i);
        (*(freq + temp))++;
    }
}
