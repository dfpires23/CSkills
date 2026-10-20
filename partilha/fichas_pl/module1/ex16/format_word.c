void format_word(char *str) {
    if (*str >= 'a' && *str <= 'z') {
        *str -= 32;
    }

    str++;

    while (*str != '\0' && *str != ' ') {
        if (*str >= 'A' && *str <= 'Z') {
            *str += 32;
        }
        str++;
    }
}
