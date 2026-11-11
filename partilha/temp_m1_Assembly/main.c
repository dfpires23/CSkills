/*
    1230414: Daniel Ferreira Pires: 2NC: Version I
*/
#include "func2.h"
#include <stdio.h>

int main() {
    long long robots[5] = {
        0x0BB80BB80BB80A01, // ID 1 (Has capacity)
        0x07D007D007D00502, // ID 2 (Does not have capacity)
        0x01F401F401F40103, // ID 3 (Does not have capacity)
        0x0000000000000004, // ID 4 (Has capacity)
        0x0000000000000005  // ID 5 (Has capacity)
    };
    int n = 5;
    unsigned char array[5]; // Array to store IDs of robots without capacity

    printf("--- ROBOTS ---\n");
    for (int i = 0; i < n; i++) {
        // Print the robot's address in hexadecimal format
        printf("Robots: 0x%016llX\n", *(robots + i));
    }

    int count = func2(robots, n, array);

    printf("\n--- RESULTS ---\n");
    printf("Number of robots WITHOUT capacity:\n%d\n", count);

    if (count > 0) {
        printf("IDs of robots WITHOUT capacity: \n");
        for (int i = 0; i < count; i++) {
            // Access the stored IDs using pointer arithmetic
            printf("0x%02X\n", *(array + i));
        }
    }

    return 0;
}