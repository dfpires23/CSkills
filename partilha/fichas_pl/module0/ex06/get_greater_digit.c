#include "../ex05/cmp.h"

int get_greater_digit(int n) {
    int max = 0, num;

    while (n > 0) {
        num = n % 10;
        if (cmp(max, num) == -1)
            max = num;
        n /= 10;
    }

    return max;
}
