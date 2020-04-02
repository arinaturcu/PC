// Turcu Arina Emanuela 313CA

#include <stdio.h>
#include <stdlib.h>
#include "task1.h" // task_1() returns a double value
#include "task2.h" // task_2() makes changes in the map; doesn't print anything
#include "task3.h"

int** read_alloc_map(int n, int* dim) {
    int **map;

    map = (int**) malloc(n * sizeof (int*));

    for (int i = 0; i < n; ++i) {
        scanf("%d", &dim[i]);

        map[i] = (int*) malloc(dim[i] * sizeof (int));

        for (int j = 0; j < dim[i]; ++j) {
            scanf("%X", &map[i][j]);
        }
    }
    return map;
}

void print_map(int n, int** map, int* dim) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < dim[i]; ++j) {
            printf("%08X ", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, **map, *dim;
    double shield;

    scanf("%d", &n);

    dim = (int*) malloc(n * sizeof(int));
    map = read_alloc_map(n, dim);

    if (map == NULL || dim == NULL) {
        printf("Memory couldn't be allocated!\n");
        return -1;
    }

    shield = task_1(n, map, dim);

    task_2(map, dim);

    printf("task 1\n%0.7lf\n", shield); // task 1

    printf("task 2\n");
    print_map(n, map, dim);

    printf("task 3\n");
    task_3(n, map, dim);

    free(dim);
    for (int i = 0; i < n; ++i) {
        free(map[i]);
    }
    free(map);

    return 0;
}
