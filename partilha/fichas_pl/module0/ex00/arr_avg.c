#include <stdio.h>

float arr_avg(int[], int);

int main(void) {
    int arr[10];
    float avg = 0.0;

    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    avg = arr_avg(arr, 10);

    printf("Average = %.2f\n", avg);
    return 0;
}

float arr_avg(int arr[], int arr_size) {
    int sum = 0;

    for (int i = 0; i < arr_size; i++) {
        sum += arr[i];
    }

    return (float)sum / arr_size;
}