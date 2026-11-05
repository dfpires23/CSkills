#include <stdio.h>

void swap_pointers(int **b, int **s, int n);

int main(void) {
    int data1[5] = {1, 2, 3, 4, 5};
    int data2[5] = {10, 20, 30, 40, 50};
    int *bigger = data1;
    int *smaller = data2;
    printf("Bigger: %p, Smaller: %p\n", bigger, smaller);

    swap_pointers(&bigger, &smaller, 5);
    printf("Bigger: %p, Smaller: %p\n", bigger, smaller);

    return 0;
}

void swap_pointers(int **b, int **s, int n) {

    int sum1 = 0, sum2 = 0;

    for (int i = 0; i < n; i++) {
        sum1 += *(*b + i);
        sum2 += *(*s + i);
    }

    if (sum1 < sum2) {
        int *temp = *b;
        *b = *s;
        *s = temp;
    }
}