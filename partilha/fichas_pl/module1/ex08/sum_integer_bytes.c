int sum_integer_bytes(unsigned int *p) {
    unsigned char *c = (unsigned char *)p;

    return *c + *(c + 1) + *(c + 2) + *(c + 3);
}
