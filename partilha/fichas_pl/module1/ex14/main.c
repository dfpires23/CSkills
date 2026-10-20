#include "count_words.h"
#include <stdio.h>

int main(void) {
    char str[] = "     the     numBERr     must be  saved";

    printf("%d\n", count_words(str));

    return 0;
}
