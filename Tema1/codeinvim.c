// Copyright 2019 Arina Emanuela Turcu 313 CA

#include <stdio.h>
#define NMAX 100

int main() {
    int materii, note[NMAX], credite[NMAX], p_min, pct = 0;
// citim nuamrul de materii, notele si creditele si calculam punctele actuale
    scanf("%d", &materii);

    int i;
    for (i = 0; i < materii; ++i) {
        scanf("%d", &note[i]);
    }
    for (i = 0; i < materii; ++i) {
        scanf("%d", &credite[i]);
        pct += credite[i] * note[i];
    }
    scanf("%d", &p_min);

// punem punctele obtinute daca ar avea nota 10 materiile la care
// nu a luat 10 in vectorul crestere

    int crestere[NMAX], j = 0;

    for (i = 0; i < materii; ++i) {
        if (note[i] != 10) {
            crestere[j] = (10 - note[i]) * credite[i];
            j++;
        }
    }

// sortam vectorul crestere[] descrescator

    int mic = j, aux;

    for (i = 0; i < mic; ++i) {
        for (j = i + 1; j < mic; ++j) {
            if (crestere[i] < crestere[j]) {
                aux = crestere[i];
                crestere[i] = crestere[j];
                crestere[j] = aux;
            }
        }
    }

    int m = 0;

    for (i = 0; i < mic; ++i) {
        if (pct + crestere[i] >= p_min) {
            m++;
            break;
        }
        m++;
        pct += crestere[i];
    }

    if (!m) {
        printf("%s\n", "-1");
    } else {
        printf("%d\n", m);
    }

    return 0;
}
