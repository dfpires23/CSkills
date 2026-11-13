#include "asm.h"
#include <stdio.h>

int main(void) {
    char arr1[] = {'A', 'B', 'C', 'D'};
    char arr2[] = {'1', '2', '3', '4'};

    int num = 4;

    swap(arr1, arr2, num);

    printf("Array 1: ");
    for (int i = 0; i < num; i++) {
        printf("%c ", arr1[i]);
    }

    printf("\nArray 2: ");
    for (int i = 0; i < num; i++) {
        printf("%c ", arr2[i]);
    }

    printf("\n");

    return 0;
}