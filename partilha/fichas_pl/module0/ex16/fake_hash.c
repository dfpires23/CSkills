#include "../ex02/sum.h"
#include "../ex07/get_ascii_code.h"

int fake_hash(char str[]) {
    int s = 0;
    int i = 0;

    while (str[i] != '\0') {
        s = sum(s, get_ascii_code(str[i]));
        i++;
    }

    return s;
}
