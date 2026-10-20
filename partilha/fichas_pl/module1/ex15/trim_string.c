void trim_string(char *str) {
    char *read = str;
    char *write = str;

    while (*read == ' ') {
        read++;
    }

    while (*read != '\0') {
        if (*read != ' ') {
            *write = *read;
            write++;
        } else if (*(read + 1) != ' ' && *(read + 1) != '\0') {
            *write = ' ';
            write++;
        }
        read++;
    }
    
    *write = '\0';
}
