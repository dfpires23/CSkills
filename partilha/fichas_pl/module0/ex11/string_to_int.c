#include "../ex07/get_ascii_code.h"

int string_to_int(char str[]) {
    int i = 0;
    int result = 0;

    while (str[i] != '\0') {
        result = result * 10 + get_ascii_code(str[i]) - get_ascii_code('0');
        i++;
    }

    return result;
}
