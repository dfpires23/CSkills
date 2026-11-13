#include "file2.h"
#include <stdio.h>
#define N 100
#define M 9

int main(void) {
    char str[N] = "Running Into Segfaults Causes Vexation.";
    char upp[M];
    printf("%s\n", str);
    printf("\n");

    int num = func2(str, upp, M);
    printf("*****Number of characters copied: %d\n", num);
    printf("\n");

    printf("*****The characters copied: %s\n", upp);
    return 0;
}
