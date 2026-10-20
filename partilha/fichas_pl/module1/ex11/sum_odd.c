int sum_odd(int *p) {
    int sum = 0;

    for (int i = 1; i <= *p; i++) {
        if (*(p + i) % 2 != 0) {
            sum += *(p + i);
        }
    }

    return sum;
}
