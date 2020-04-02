// Copyright 2019 Arina Emanuela Turcu 313 CA

#include <stdio.h>

int special(int x1, int x2, int x3) {
    if (x1 != 0 && x3 != 0 && x1 < x2 && x2 > x3) {
        return 1;
    }

    return 0;
}

int main() {
    int n, x1 = 0, x2 = 0, x3, ok = 0, ok_min = 0, ok_max = 0;
    int contor = 0, max = 0, pozitie = -1, min = 1000000;
    long sum = 0;

    scanf("%d", &n);

    while (n) {
        scanf("%d", &x3);

        if (special(x1, x2, x3)) {
            sum += x2;
            contor++;
            ok = 1;

            if (x2 > max && pozitie % 2 != 0) {
                max = x2;
                ok_max = 1;
            }

            if (x2 < min && pozitie % 2 == 0) {
                min = x2;
                ok_min = 1;
            }
        }

        x1 = x2;
        x2 = x3;

        pozitie++;

        n--;
    }

    if (!ok) {        // in caz ca nu s-au gasit copaci speciali,
        contor = 1;   // suma va fi 0, facand impartirea la contor imposibila
        min = 0;
    } else {
        if (!ok_min) {
            min = -1; // daca nu s-au gasit copaci speciali pe pozitie para
        }
        if (!ok_max) {
            max = -1; // daca nu s-au gasit copaci speciali pe pozitie impara
        }
    }

    printf("%ld\n", sum);
    printf("%0.7f\n", 1.0*sum/contor);
    printf("%d\n", max);
    printf("%d\n", min);

    return 0;
}
