int sort_without_reps(short *src, int n, short *dest) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (*(src + j) > *(src + j + 1)) {
                int temp = *(src + j);
                *(src + j) = *(src + j + 1);
                *(src + j + 1) = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        *(dest + i) = *(src + i);
    }

    int count = 0;

    for (int i = 0; i < n; i++) {
        if (count == 0 || *(dest + i) != *(dest + count - 1)) {
            *(dest + count) = *(dest + i);
            count++;
        }
    }

    return count;
}
