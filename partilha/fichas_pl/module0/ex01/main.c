#include <stdio.h>

int main(void) {
    printf("char: %zu\n", sizeof(char));
    printf("int: %zu\n", sizeof(int));
    printf("unsigned int: %zu\n", sizeof(unsigned int));
    printf("long: %zu\n", sizeof(long));
    printf("short: %zu\n", sizeof(short));
    printf("long long: %zu\n", sizeof(long long));
    printf("float: %zu\n", sizeof(float));
    printf("double: %zu\n", sizeof(double));
    return 0;
}
