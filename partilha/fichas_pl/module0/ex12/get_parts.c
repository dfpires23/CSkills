#include "../ex11/string_to_int.h"
#include <string.h>

static int counter(char x[]) {
    int i = 0;

    while (x[i] != '.') {
        i++;
    }

    return i;
}

int integer_part(char x[]) {
    int index = counter(x);
    char s[100];

    strncpy(s, x, index);
    s[index] = '\0';

    return string_to_int(s);
}

int fractional_part(char x[]) {
    int index = counter(x);
    char s[100];
    int i = 0;

    while (x[index + 1 + i] != '\0') {
        s[i] = x[index + 1 + i];
        i++;
    }

    s[i] = '\0';

    return string_to_int(s);
}
