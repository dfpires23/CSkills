#include "../ex02/sum.h"

int mul(int a, int b) {
    int s = 0;

    for (int i = 0; i < a; i++) {
        s = sum(s, b);
    }

    return s;
}
