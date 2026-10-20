void swap(short *vec1, short *vec2, int size) {
	for (int i = 0; i < size; i++) {
		short temp = *(vec1 + i);
		*(vec1 + i) = *(vec2 + i);
		*(vec2 + i) = temp;
	}
}
