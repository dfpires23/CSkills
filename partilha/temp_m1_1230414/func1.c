/*
    1230414: Daniel Ferreira Pires: 2NC: Version I
*/

int func1(long long *robot) {
    unsigned char *ptr = (unsigned char *)robot;

    // Read the battery by advancing 1 byte from the base address
    unsigned char bateria_km = *(ptr + 1);

    // Advance 2 bytes from the base and convert to a short pointer
    unsigned short *trips = (unsigned short *)(ptr + 2);

    // Read the shorts by advancing the pointer (automatically skips 2 bytes at
    // a time)
    unsigned short trip1 = *(trips);     // Equivalent to trips[0]
    unsigned short trip2 = *(trips + 1); // Equivalent to trips[1]
    unsigned short trip3 = *(trips + 2); // Equivalent to trips[2]

    unsigned int total_meters = trip1 + trip2 + trip3;
    unsigned int bateria_meters = bateria_km * 1000;

    if (total_meters > bateria_meters) {
        return 1;
    }

    return 0;
}
