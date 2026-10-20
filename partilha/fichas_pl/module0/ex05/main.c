#include "cmp.h"
#include <stdio.h>

int main(void) {
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);

    printf("%d\n", cmp(a, b));
    return 0;
}
