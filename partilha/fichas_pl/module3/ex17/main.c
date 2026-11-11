#include "asm.h"
#include <stdio.h>

int main(void) {
    int arr[] = {5, 2, 8, 1};
    int num = 4;

    array_sort(arr, num);

    printf("Array: ");
    for (int i = 0; i < num; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}