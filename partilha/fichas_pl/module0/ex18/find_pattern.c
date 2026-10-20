#include "../ex05/cmp.h"
#include "../ex10/size_string.h"

int find_pattern(char str[], char patt[]) {
    int i = 0;
    int countA = 0;
    int len = size_string_correct(patt);

    while (str[i] != '\0') {
        int j = 0;

        while (j < len && str[i + j] != '\0' && cmp(str[i + j], patt[j]) == 0) {
            j++;
        }

        if (j == len)
            countA++;
        i++;
    }

    return countA;
}
