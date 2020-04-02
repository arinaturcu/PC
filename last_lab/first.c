#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	return *(int*) a - *(int*) b; // crescator
}

int main(int argc, char *argv[]) {

	if (argc < 2) {
		printf("Gigele, cel putin 2!\n");
		return 2;
	}

	int *v;
	v = malloc(argc * sizeof(int));

	for (int i = 1; i < argc; ++i) {
		if ( atoi(argv[i]) <= 0 ) {
			
			printf("Gigele, da-mi numere naturale!\n");
			free(v);
			
			return -1;
		}
	}

	for (int i = 1; i < argc; ++i) {
		v[i - 1] = atoi(argv[i]);
	}

	qsort(v, argc - 1, sizeof(int), cmp);

	for (int i = 0; i < argc - 1; ++i) {
		printf("%d ", v[i]);
	}

	printf("\n");

	free(v);

	return 0;
}