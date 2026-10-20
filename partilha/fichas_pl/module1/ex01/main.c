#include <stdio.h>

int main(void) {
    int x = 5;
    int *ptr_x = &x;
    float y = *ptr_x + 3;

    printf("x=%d, y=%.2f\n", x, y); // the value of x and y
    printf("&x=%p, &y=%p, ptr_x=%p\n", &x, &y,
           &ptr_x);                     // the address of x, y and ptr_x
    printf("ptr_x=%p\n", ptr_x);        // the value of ptr_x
    printf("valor ptr_x=%d\n", *ptr_x); // the value pointed by ptr_x

    int vec[] = {10, 20, 30, 40};
    int *ptr_vec = vec;
    int z = *ptr_vec;
    int h = *(ptr_vec + 3);

    printf("z=%d, h=%d\n", z, h); // the value of z and h
    printf("&vec=%p, ptr_x=%p\n", &vec,
           &ptr_vec); // the address of vec and ptr_vec
    printf("ptr_vec=%p, vec=%p\n", ptr_vec,
           vec);                            // the value of ptr_vec and vec
    printf("valor ptr_vec=%d\n", *ptr_vec); // the value pointed by ptr_vec

    for (int i = 0; i < 4; i++) {
        printf("1: %p,%d\t", &vec[i], vec[i]);
    }
    printf("\n");
    for (ptr_vec = vec; ptr_vec < vec + 4; ptr_vec++) {
        printf("2: %p,%d\t", ptr_vec, *ptr_vec);
    }
    printf("\n");
    for (ptr_vec = vec + 3; ptr_vec >= vec; ptr_vec--) {
        printf("3: %p,%d\t", ptr_vec, *ptr_vec);
    }

    int a;
    printf("\n");
    ptr_vec = vec;
    printf("4: %p,%d\n", ptr_vec, *ptr_vec);
    a = *ptr_vec++;
    printf("5: %p,%d,%d\n", ptr_vec, *ptr_vec, a);
    ptr_vec = vec;
    a = (*ptr_vec)++;
    printf("6: %p,%d,%d\n", ptr_vec, *ptr_vec, a);
    ptr_vec = vec;
    a = *++ptr_vec;
    printf("7: %p,%d,%d\n", ptr_vec, *ptr_vec, a);
    ptr_vec = vec;
    a = ++*ptr_vec;
    printf("8: %p,%d,%d\n", ptr_vec, *ptr_vec, a);
    printf("\n");
    for (ptr_vec = vec; ptr_vec < vec + 4; ptr_vec++) {
        printf("9: %p,%d\t", ptr_vec, *ptr_vec);
    }

    printf("\n");
    unsigned int d = 0xAABBCCDD;
    printf("10: %p,%x\t", &d, d);
    printf("\n");
    unsigned char *ptr_d = (unsigned char *)&d;
    unsigned char *p;
    for (p = ptr_d; p < ptr_d + sizeof(unsigned int); p++) {
        printf("11: %p,%x\t", p, (unsigned char)*p);
    }

    return 0;
}
