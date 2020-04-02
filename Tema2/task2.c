// Turcu Arina Emanuela 313CA

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// realloc minimum blocks of type int
int new (unsigned int poz, unsigned int siz) {
    unsigned int c = 1;

    while (poz * siz > c * sizeof(int)) {
        c++;
    }

    return c * sizeof(int);
}

void modify(int** map, int* dim, char type[1], int line, int index) {
    int replace_value;
    scanf("%X", &replace_value);

    if (strstr(type, "C")) {
        char *p = (char*) &map[line][0];

        if (index / ((int)sizeof(int)/(int)sizeof(char)) >= dim[line]) {
            map[line] = realloc(map[line], new(index, sizeof(char)));

            p = (char*) &map[line][0];

            for (int i = dim[line]; i < new(index, sizeof(char)) / 4; ++i) {
                map[line][i] = 0;
            }

            dim[line] = new(index, sizeof(char)) / 4;
        }

        *(p + index - 1) = (char)replace_value;

    } else {
        if (strstr(type, "S")) {
            short *p = (short*) &map[line][0];

            if (index / ((int)sizeof(int)/(int)sizeof(short)) >= dim[line]) {
                map[line] = realloc(map[line], new(index, sizeof(short)));

                p = (short*) &map[line][0];

                for (int i=dim[line]; i < new(index, sizeof(short))/4; ++i) {
                    map[line][i] = 0;
                }

                dim[line] = new(index, sizeof(short)) / 4;
            }

            *(p + index - 1) = replace_value;

        } else {
            if (strstr(type, "I")) {
                int *p = (int*) &map[line][0];

                if (index / ((int)sizeof(int)/(int)sizeof(int)) >= dim[line]) {
                    map[line] = realloc(map[line], new(index, sizeof(int)));

                    p = (int*) &map[line][0];

                    for (int i=dim[line]; i < new(index, sizeof(int))/4; ++i) {
                        map[line][i] = 0;
                    }

                    dim[line] = new(index, sizeof(int)) / 4;
                }

                *(p + index - 1) = replace_value;
            }
        }
    }
}

void delete(int** map, char type[1], int line, int index) {
    if (strstr(type, "C")) {
        char *p;

        p = (char*) &map[line][0];
        *(p + index - 1) = 0;

    } else {
        if (strstr(type, "S")) {
            short *p;

            p = (short*) &map[line][0];
            *(p + index - 1) = 0;

        } else {
            if (strstr(type, "I")) {
                int *p;

                p = (int*) &map[line][0];
                *(p + index - 1) = 0;
            }
        }
    }
}

void swap(int** map, char type[1], int line, int index) {
    if (strstr(type, "C")) {
        char *p;
        p = (char*) &map[line][0];

        char *aux;
        aux = p + index;

        char copy[sizeof(*p)];

        for (int i = 0; i < (int)sizeof(*p); ++i) {
            copy[i] = *(aux + i);
        }

        int k = 0;
        for (int i = (int)sizeof(*p) - 1; i >= 0; --i) {
            aux[k] = copy[i];
            k++;
        }

    } else {
        if (strstr(type, "S")) {
            short *p;
            p = (short*) &map[line][0];

            char *aux;
            aux = (char*)(p + index);

            char copy[sizeof(*p)];

            for (int i = 0; i < (int)sizeof(*p); ++i) {
                copy[i] = *(aux + i);
            }

            int k = 0;
            for (int i = (int)sizeof(*p) - 1; i >= 0; --i) {
                aux[k] = copy[i];
                k++;
            }

        } else {
            if (strstr(type, "I")) {
                int *p;
                p = &map[line][0];

                char *aux;
                aux = (char*)(p + index);

                char copy[sizeof(*p)];

                for (int i = 0; i < (int)sizeof(*p); ++i) {
                    copy[i] = *(aux + i);
                }

                int k = 0;
                for (int i = (int)sizeof(*p) - 1; i >= 0; --i) {
                    aux[k] = copy[i];
                    k++;
                }
            }
        }
    }
}

void task_2(int** map, int* dim) {
    int no_op, line, index;
    char oper[1], type[1];

    scanf("%d", &no_op);

    while (no_op) {
        scanf("%s %s %d %d", oper, type, &line, &index);

        if (strstr(oper, "M")) {
            modify(map, dim, type, line, index);
        } else {
            if (strstr(oper, "D")) {
                delete(map, type, line, index);
            } else {
                if (strstr(oper, "S")) {
                    swap(map, type, line, index);
                }
            }
        }

        no_op--;
    }
}
