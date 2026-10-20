#include <stdio.h>
#include "swap.h"

int main(void) {
	short vec1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	short vec2[] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
	
	swap(vec1, vec2, 10);

    for (int i = 0; i < 10; i++) {
        printf("%d ", *(vec1 + i));
    }
    printf("\n");

    for (int i = 0; i < 10; i++) {
        printf("%d ", *(vec2 + i));
    }
    printf("\n");

	return 0;
}
