// Turcu Arina Emanuela 313CA

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int greatest(int *supermass, int k) {
    int max = 0, order = 0;
    for (int i = 0; i < k; ++i) {
        if (supermass[i] > max) {
            max = supermass[i];
            order = i;
        }
    }

    return order;
}

void search(int n, char **copy, int* dim, int i, int j, int* supermass, int k) {
    supermass[k]++;
    copy[i][j] = 0x99;
    if (i - 1 >= 0 && dim[i - 1] * 4 > j && copy[i - 1][j] == 0) {
        search(n, copy, dim, i - 1, j, supermass, k);
    }

    if (i + 1 < n && dim[i + 1] * 4 > j && copy[i + 1][j] == 0) {
        search(n, copy, dim, i + 1, j, supermass, k);
    }

    if (j - 1 >= 0 && copy[i][j - 1] == 0) {
        search(n, copy, dim, i, j - 1, supermass, k);
    }

    if (j + 1 < dim[i] * 4 && copy[i][j + 1] == 0) {
        search(n, copy, dim, i, j + 1, supermass, k);
    }
}

void task_3(int n, int** map, int* dim) {
    char *p;
    int nr_black_holes = 0;
    int* supermass;
    char **copy;

    copy = (char**) map;

    for (int i = 0; i < n; ++i) {
        p = (char*) &map[i][0];

        for (int j = 0; j < dim[i] * 4; ++j) {
            if (*(p + j) == 0) {
                nr_black_holes++;
            }
        }
    }

    supermass = (int*)malloc(nr_black_holes * sizeof(int));

    int *x_ax, *y_ax;
    x_ax = (int*)malloc(sizeof(int));
    y_ax = (int*)malloc(sizeof(int));

    for (int i = 0; i < nr_black_holes; ++i) {
        supermass[i] = 0;
    }

    if (supermass == NULL || x_ax == NULL || y_ax == NULL) {
        printf("Memory couldn't be allocated in task 3!\n");
        return;
    }

    int k = 0;

    for (int i = 0; i < n; ++i) {;
        for (int j = 0; j < dim[i] * 4; ++j) {
            if (copy[i][j] == 0) {
                search(n, copy, dim, i, j, supermass, k);

                x_ax[k] = i;
                y_ax[k] = j;

                k++;

                x_ax = (int*)realloc(x_ax, (k + 1) * sizeof(int));
                y_ax = (int*)realloc(y_ax, (k + 1) * sizeof(int));
            }
        }
    }

    supermass = (int*)realloc(supermass, k * sizeof(int));

    if (supermass == NULL || x_ax == NULL || y_ax == NULL) {
        printf("Memory couldn't be allocated in task 3!\n");
        return;
    }

    int ind_max = greatest(supermass, k);

    printf("%d %d %d\n", x_ax[ind_max], y_ax[ind_max], supermass[ind_max]);

    free(x_ax);
    free(y_ax);
    free(supermass);
}
