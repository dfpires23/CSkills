#include "../ex05/cmp.h"
#include "../ex16/fake_hash.h"

int check_string(char str[], int h) {
    if (!cmp(fake_hash(str), h)) {
        return 0;
    } else {
        return 1;
    }
}
