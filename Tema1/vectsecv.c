// Copyright 2019 Arina Emanuela Turcu 313 CA

#include <stdio.h>
#define NMAX 100
// functia creeaza numarul format din cifrele in ordine
// descrescatoare ale lui x
int n_descrescator(int x) {
    int cifre[9], n = 0;

    while (x) {
        cifre[n++] = x % 10;
        x /= 10;
    }

    int i, j, aux;
    for (i = 0; i < n; ++i) {
        for (j = i + 1; j < n; ++j) {
            if (cifre[i] < cifre[j]) {
                aux = cifre[i];
                cifre[i] = cifre[j];
                cifre[j] = aux;
            }
        }
    }
    x = i = 0;

    do {
        x = x*10 + cifre[i++];
    } while (i < n);

    return x;
}
// functia creeaza numarul format din cifrele in ordine
// crescatoare ale lui x
int n_crescator(int x) {
    int cifre[9], n = 0;

    while (x) {
        cifre[n++] = x % 10;
        x /= 10;
    }

    int i, j, aux;
    for (i = 0; i < n; ++i) {
        for (j = i + 1; j < n; ++j) {
            if (cifre[i] > cifre[j]) {
                aux = cifre[i];
                cifre[i] = cifre[j];
                cifre[j] = aux;
            }
        }
    }
    x = i = 0;

    do {
        x = x*10 + cifre[i++];
    } while (i < n);

    return x;
}

int diferenta(int x) {
    return n_descrescator(x) - n_crescator(x);
}

int main() {
    int n, secventa[NMAX] = {0}, contor = 0, i, j, ok = 0;
    scanf("%d", &n);

    for (i = 0; i < NMAX; ++i) {
        secventa[i] = diferenta(n);
        n = diferenta(n);

        for (j = 0; j < i; ++j) {
            if (secventa[j] == secventa[i]) {
                ok = 1;
                break;
            }
        }

        if (ok) {
            break;
        }
    }

    int elem_perioada = secventa[i];
    int afara = 0;
    contor = i;

    for (i = 0; i < contor; ++i) {
        if (secventa[i] != elem_perioada) {
            afara++;
        } else {
            break;
        }
    }

    for (i = 0; i < contor - afara; ++i) {
        secventa[i] = secventa[i + afara];
    }

    printf("%d\n", afara);

    for (i = 0; i < contor - afara; ++i) {
        printf("%d ", secventa[i]);
    }

    printf("\n");
    return 0;
}
