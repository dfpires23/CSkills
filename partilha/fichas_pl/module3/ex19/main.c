#include "asm.h"
#include <stdio.h>

int main() {
    char grades[] = {10, 15, 10, 12, 15, 10, 20};
    int freq[21];
	int num = 7;

    frequencies(grades, num, freq);

    for (int i = 0; i <= 20; i++) {
		if (freq[i] > 0) {
        	printf("%d: %d\n", i, freq[i]);
		}
    }

    return 0;
}