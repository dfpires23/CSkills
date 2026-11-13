#include "asm.h"
#include <stdio.h>
#include <string.h>

int main(void) {
    int res;
    char op1[100];

    printf("Valor op1: ");
    fgets(op1, sizeof(op1), stdin);

    op1[strcspn(op1, "\n")] = '\0';

    res = encrypt(op1);
    printf("Encrypted: %s\n", op1);
    printf("res = %d\n", res);

    res = decrypt(op1);
    printf("Decrypted: %s\n", op1);
    printf("res = %d\n", res);

    return 0;
}
