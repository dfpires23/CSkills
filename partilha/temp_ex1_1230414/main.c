/*
    1230414: Daniel Ferreira Pires: 2NC: Version A
*/

#include "func2.h"
#include <stdio.h>
#define NCARS 5

int main(void) {
    unsigned int cars[NCARS] = {0xFFFFFFFF, 0xFFFAFFFA, 0x00000000, 0xFCFDEFAB,
                                0xFFFFFFFF};
    unsigned int *fill[NCARS];

    printf("Number=%d\n", check_tires(cars, NCARS, fill));

    return 0;
}
