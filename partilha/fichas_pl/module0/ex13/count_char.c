#include "../ex08/get_ascii_char.h"

int count_char(char str[], int c) {
    int i = 0;
    int count = 0;
    char ch = get_ascii_char(c);

    while (str[i] != '\0') {
        if (str[i] == ch)
            count++;
        i++;
    }

    return count;
}
