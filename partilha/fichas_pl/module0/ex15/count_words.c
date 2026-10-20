#include "../ex07/get_ascii_code.h"
#include "../ex13/count_char.h"

int count_words(char str[]) {
    int code = get_ascii_code(' ');

    return count_char(str, code) + 1;
}
