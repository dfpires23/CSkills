#include <stdio.h>

int main(void) {
    double f = 12.0;
    int d = 10;
    char c = 'A';

    double *ptr_f = &f;
    int *ptr_d = &d;
    char *ptr_c = &c;

    printf("&f: %p, val=%.2f, size=%d\n", ptr_f, *ptr_f, sizeof(ptr_f));
    printf("&d: %p, val=%d, size=%d\n", ptr_d, *ptr_d, sizeof(ptr_d));
    printf("&c: %p, val=%c, size=%d\n", ptr_c, *ptr_c, sizeof(ptr_c));

    return 0;
}
