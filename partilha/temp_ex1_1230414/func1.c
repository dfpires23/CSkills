/*
    1230414: Daniel Ferreira Pires: 2NC: Version A
*/

int low_pressure(unsigned int *x) {
    unsigned char *p = (unsigned char *)x;
    for (int i = 0; i < 4; i++) {
        if (*(p + i) < 0xFE) {
            return 1;
        }
    }
    return 0;
}
