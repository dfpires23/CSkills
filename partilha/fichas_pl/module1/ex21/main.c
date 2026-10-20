#include <stdio.h>
#include <stdlib.h>

#define DATA_LENGTH 5

void init_data(int *data, int n);
void print_data(int *data, int n);
void init_data_ptrs(int *data, int n, int **ptrs);
void print_data_ptrs(int **ptrs, int n);
int *find_max_data_ptrs(int **ptrs, int n);
void sort_data_ptrs(int **ptrs, int n);

int main(void) {
    int data[DATA_LENGTH];
    int *data_ptrs[DATA_LENGTH];
    int *res;

    init_data(data, DATA_LENGTH);
    print_data(data, DATA_LENGTH);
    init_data_ptrs(data, DATA_LENGTH, data_ptrs);
    print_data_ptrs(data_ptrs, DATA_LENGTH);
    res = find_max_data_ptrs(data_ptrs, DATA_LENGTH);
    printf("0x%x\n", *res);
    sort_data_ptrs(data_ptrs, DATA_LENGTH);
    print_data_ptrs(data_ptrs, DATA_LENGTH);

    return 0;
}

// a)
void init_data(int *data, int n) {
    for (int i = 0; i < n; i++) {
        *(data + i) = rand() % 50;
    }
}

// b)
void print_data(int *data, int n) {
    for (int i = 0; i < n; i++) {
        printf("0x%x ", *(data + i));
    }
    printf("\n");
}

// c)
void init_data_ptrs(int *data, int n, int **ptrs) {
    for (int i = 0; i < n; i++) {
        *(ptrs + i) = data + i;
    }
}

// d)
void print_data_ptrs(int **ptrs, int n) {
    for (int i = 0; i < n; i++) {
        printf("%p=0x%x\n", *(ptrs + i), **(ptrs + i));
    }
}

// e)
int *find_max_data_ptrs(int **ptrs, int n) {
    int max = **ptrs;
    int *res = *ptrs;
    for (int i = 1; i < n; i++) {
        if (max < **(ptrs + i)) {
            max = **(ptrs + i);
            res = *(ptrs + i);
        }
    }

    return res;
}

// f)
// Bubble sort:
void sort_data_ptrs(int **ptrs, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (**(ptrs + j) > **(ptrs + j + 1)) {
                int temp = **(ptrs + j);
                **(ptrs + j) = **(ptrs + j + 1);
                **(ptrs + j + 1) = temp;
            }
        }
    }
}

// Selection sort:
// void sort_data_ptrs(int **ptrs, int n) {
//     for (int i = 0; i < n - 1; i++) {
//         for (int j = i + 1; j < n; j++) {
//             if (**(ptrs + i) < **(ptrs + j)) {
//                 int *temp = *(ptrs + i);
//                 *(ptrs + i) = *(ptrs + j);
//                 *(ptrs + j) = temp;
//             }
//         }
//     }
// }
