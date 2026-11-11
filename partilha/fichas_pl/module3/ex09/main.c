#include "asm.h"
#include <stdio.h>

int main(void) {
    int num, x;
    int *res;

    printf("Valor num: ");
    scanf("%d", &num);

    int op1[num];

    for (int i = 0; i < num; i++) {
        printf("Valor op1[%d]: ", i);
        scanf("%d", &op1[i]);
    }

    printf("Valor x: ");
    scanf("%d", &x);

    res = vec_search(op1, num, x);

    if (res != NULL)
        printf("res = %p\n", (void *)res);
    else
        printf("res = NULL\n");

    return 0;
}
