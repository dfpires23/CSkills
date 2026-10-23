/*
    1230414: Daniel Ferreira Pires: 2NC: Version I
*/
#include "func1.h"

int func2(long long *robots, int n, unsigned char *array) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        // Pass the robot's address by iterating over the original pointer:
        // (robots + i)
        if (func1(robots + i) == 1) {
            unsigned char *ptr = (unsigned char *)(robots + i);

            // Store the ID in the output array using pointer arithmetic
            *(array + count) = *(ptr);
            count++;
        }
    }

    return count;
}
