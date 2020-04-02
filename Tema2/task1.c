// Turcu Arina Emanuela 313CA

double task_1(int n, int** map, int* dim) {
    char *p;
    int sum = 0, contor = 0, i, j, k;

    for (j = 0; j < dim[0]; ++j) {     // pentru marginea de sus
        p = (char*) &map[0][j];

        for (k = 0; k < 4; ++k) {
            sum += *(p + k);
            contor++;
        }
    }

    for (j = 0; j < dim[n - 1]; ++j) { // pentru marginea de jos
        p = (char*) &map[n - 1][j];

        for (k = 0; k < 4; ++k) {
            sum += *(p + k);
            contor++;
        }
    }

    for (i = 1; i < n - 1; ++i) {
        if (dim[i] != 1) {
            for (j = 0; j < dim[i]; ++j) {
                if (j == 0) {            // pentru marginea din stanga
                    p = (char*) &map[i][j];

                    sum += *(p + 0);
                    contor++;
                } else {
                    if (j == dim[i] - 1) { // pentru marginea din dreapata
                        p = (char*) &map[i][j];

                        sum += *(p + 3);
                        contor++;
                    }
                }
            }

        } else {
            p = (char*) &map[i][0];
            sum += *(p + 0) + *(p + 3);
            contor += 2;
        }
    }
    double medie = 1.0*sum/contor;
    return medie;
}
