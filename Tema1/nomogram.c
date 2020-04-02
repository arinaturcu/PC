// Copyright 2019 Arina Emanuela Turcu 313 CA

#include <stdio.h>
#define NMAX 100

void citire_res(int n, int m, int r_lin[NMAX][NMAX], int r_col[NMAX][NMAX]) {
    int i, j;

    for (i = 0; i < n; ++i) {
        scanf("%d", &r_lin[i][0]);
        for (j = 1; j <= r_lin[i][0]; ++j) {
            scanf("%d", &r_lin[i][j]);
        }
    }

    for (i = 0; i < m; ++i) {
        scanf("%d", &r_col[i][0]);
        for (j = 1; j <= r_col[i][0]; ++j) {
            scanf("%d", &r_col[i][j]);
        }
    }
}

void citire_puz(int n, int m, int puz[NMAX][NMAX]) {
    int i, j;

    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            scanf("%d", &puz[i][j]);
        }
    }
}

int ver_linii(int n, int m, int r_lin[NMAX][NMAX], int puz[NMAX][NMAX]) {
    int i, j, k, negre, grupe;

    // se verifica daca grupurile de pe linii de casute negre
    // au marimea corecta daca numarul lor este corespunzator

    for (i = 0; i < n; ++i) {
        k = 1;
        negre = 0;
        grupe = 0;

        for (j = 0; j < m; ++j) {
            if (puz[i][j]) {
                if (j != m - 1) {
                    negre++;
                }
                if (j == m - 1 && negre + 1 != r_lin[i][k]) {
                    return 0;
                }
                if (j == m - 1 && negre + 1 == r_lin[i][k]) {
                    grupe++;
                }
            }

            if (!puz[i][j]) {
                if (negre && negre != r_lin[i][k]) {
                    return 0;
                }
                if (negre && negre == r_lin[i][k]) {
                    k++;
                    grupe++;
                    negre = 0;
                }
            }
        }

        if (grupe != r_lin[i][0]) {
            return 0;
        }
    }

    return 1;
}

int ver_coloane(int n, int m, int r_col[NMAX][NMAX], int puz[NMAX][NMAX]) {
    int i, j, k, negre, grupe;

    for (j = 0; j < m; ++j) {
        k = 1;
        negre = 0;
        grupe = 0;

        // se verifica daca grupurile de pe coloane de casute negre
        // au marimea corecta daca numarul lor este corespunzator

        for (i = 0; i < n; ++i) {
            if (puz[i][j]) {
                if (i != n - 1) {
                    negre++;
                }
                if (i == n - 1 && negre + 1 != r_col[j][k]) {
                    return 0;
                }
                if (i == n - 1 && negre + 1 == r_col[j][k]) {
                    grupe++;
                }
            }

            if (!puz[i][j]) {
                if (negre && negre != r_col[j][k]) {
                    return 0;
                }
                if (negre && negre == r_col[j][k]) {
                    k++;
                    grupe++;
                    negre = 0;
                }
            }
        }

        if (grupe != r_col[j][0]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int nr, n, m;
    int r_lin[NMAX][NMAX], r_col[NMAX][NMAX];
    int puz[NMAX][NMAX];

    scanf("%d", &nr);
    // verifica cele nr puzzel-uri
    while (nr) {
        scanf("%d %d", &n, &m);
        citire_res(n, m, r_lin, r_col);
        citire_puz(n, m, puz);

        if (ver_linii(n, m, r_lin, puz) && ver_coloane(n, m, r_col, puz)) {
            printf("%s\n", "Corect");
        } else {
            printf("%s\n", "Eroare");
        }
        nr--;
    }
    return 0;
}
