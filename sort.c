#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	return *(int*) b - *(int*) a; // descrescator
}

int main () {
	int v[5] = {7, 23, 5, 1, -12};

	qsort(v, 5, sizeof(int), cmp);

	for (int i = 0; i < 5; ++i) {
		printf("%d ", v[i]);
	}

	printf("\n");

	return 0;
}