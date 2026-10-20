#include <stdlib.h>
int nbr_of_sets = 0;

void populate(unsigned char *vec, int num, int limit) {
    for (int i = 0; i < num; i++) {
        *(vec + i) = rand() % limit;
    }
}

int check(int x, int y, int z) {
    if (x < y && y < z) {
        return 1;
    } else {
        return 0;
    }
}

void inc_nsets() { nbr_of_sets++; }
