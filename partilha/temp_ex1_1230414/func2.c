/*
    1230414: Daniel Ferreira Pires: 2NC: Version A
*/
#include "func1.h"

int check_tires(unsigned int *cars, int n, unsigned int **fill) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (low_pressure(cars + i)) {
            *(fill + count) = (cars + i);
            count++;
        }
    }

    return count;
}
