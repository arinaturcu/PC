#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define eps 0.00001

typedef struct {
	float x;
	float y;
} Point;

typedef struct {
	Point center;
	float r;
} Circle;

typedef struct {
	Point top_left;
	Point bottom_right;
} Rectangle;

typedef struct {
	int n;
	Point* points;
} Cloud;

int is_inside_circle(Point p, Circle c) {
	float tmp1 = (p.x - c.center.x) * (p.x - c.center.x);
	float tmp2 = (p.y - c.center.y) * (p.y - c.center.y);
	
	return (tmp1 + tmp2) <= (c.r * c.r);
}

int is_inside_rectangle(Point p, Rectangle r) {
	int vertical = (r.bottom_right.y <= p.y) && (p.y <= r.top_left.y);
	int horizontal = (r.top_left.x <= p.x) && (p.x <= r.bottom_right.x);

	return vertical && horizontal;
}
/**
 * Compara doua structuri de tip Point. Pentru a face asta, comparam membru cu
 * membru toate campurile din cele 2 structuri Point.
 * Pentru a compara variabile de tip real (float/double), nu putem folosi
 * operatorul == deoarece putem obtine rezultate eronate din cauza erorilor de
 * precizie. Deci, pentru a compara 2 astfel de variabile, trebuie sa stabilim
 * eroarea maxima pe care o dorim (sa o numim 'eps'). Astfel, daca diferenta in
 * modul dintre 2 variabile reale este mai mica decat eps, atunci consideram ca
 * variabilele sunt egale. 
 * Mate: a == b <=> |a - b| < eps, cu a si b reale (si eps = 0.00001, de exemplu) 
**/ 
int equal_points(Point p1, Point p2) {
	return (fabs(p1.x - p2.x) < eps) && (fabs(p1.y - p2.y) < eps);
}

void swap_points(Point* p1, Point* p2) {
	Point tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

/**
 * Muta elementele duplicate la finalul vectorului.
 * Returneaza numarul elementelor unice din vector.
**/
int move_duplicates(Point* points, int size) {
	int last = size - 1;

	for (int i = 1; i <= last; ++i) {
		for (int j = 0; j < i; ++j) {
			if (equal_points(points[j], points[i])) {
				swap_points(&points[i], &points[last]);
				--last;
				--i;
				break;
			}
		}
	}
	return last + 1;
}

int main() {
	FILE* in = fopen("in.txt", "rt");
	int inside_rectangle = 0, inside_circle = 0;
	Rectangle r;
	Cloud cloud;
	Circle c;

	fscanf(in, "%d", &cloud.n);
	cloud.points = (Point *)malloc(cloud.n * sizeof(Point));
	for (int i = 0; i < cloud.n; ++i) {
		fscanf(in, "%f %f", &cloud.points[i].x, &cloud.points[i].y);
	}

	fscanf(in, "%f %f %f %f", &r.top_left.x, &r.top_left.y, &r.bottom_right.x, &r.bottom_right.y);
	fscanf(in, "%f %f %f", &c.center.x, &c.center.y, &c.r);
	fclose(in);

	/* Mutam duplicatele le finalul vectorului */
	int last = move_duplicates(cloud.points, cloud.n);

	/* Deoarece last e indicele unde incep numerele duplicate, care corespunde
	   cu numarul de numere unice din vector, putem folosi in apelul realloc
	   pentru a scapa de duplicate
 	*/
	Point* new_points = (Point *)realloc(cloud.points, last * sizeof(Point));
	if (new_points != NULL) {
		cloud.points = new_points;
	}

	FILE* out = fopen("out.txt", "wt");
	for (int i = 0; i < last; ++i) {
		printf("%f %f\n", cloud.points[i].x, cloud.points[i].y);
		if (is_inside_rectangle(cloud.points[i], r)) {
			++inside_rectangle;
		}

		if (is_inside_circle(cloud.points[i], c)) {
			++inside_circle;
		}
	}

	fprintf(out, "Inside rectangle: %d\n", inside_rectangle);
	fprintf(out, "Inside circle: %d\n", inside_circle);
	free(cloud.points);
	fclose(out);
	return 0;
}
