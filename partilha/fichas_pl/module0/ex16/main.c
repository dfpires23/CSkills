#include "fake_hash.h"
#include <stdio.h>

int main(void) {
    char str[] = "I will master ARQCP";

    printf("%d\n", fake_hash(str));
    return 0;
}
