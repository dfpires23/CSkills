int count_words(char *str) {
    int count = 0;
    char *ptr = str;

    while (*str != '\0') {
        if (*str != ' ' && (str == ptr || *(str - 1) == ' ')) {
            count++;
        }
        str++;
    }

    return count;
}