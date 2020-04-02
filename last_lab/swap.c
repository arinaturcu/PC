#include <stdio.h>
#define SWAP(x,y) 



void test_int() { // interschimbare variabile de tip int
   int xi = 2, yi = 3;
   printf("%d %d\n", xi, yi);
   SWAP(xi, yi);
   printf("%d %d\n", xi, yi);
}

void test_char() { // interschimbare variabile de tip char
   char xc = 'A', yc = 'B';
   printf("%c %c\n", xc, yc);
   SWAP(xc, yc);
   printf("%c %c\n", xc, yc);
}

void test_ptr() { // interschimbare variabile de tip char*
   char* xs = "GIGEL", *ys = "NOT GIGEL";
   printf("%s %s\n", xs, ys);
   SWAP(xs, ys);
   printf("%s %s\n", xs, ys); 
}

void test_struct() { // interschimbare variabile de tip struct
    student_t xstud, ystud;
    // citire xstud, ystud
    // afisare xstud, ystud
    SWAP(xstud, ystud);
    // afisare xstud, ystud
}

void swap(void* a, void* b) {

}

int main(int argc, char* argv[]) {

  int a, b;

  scanf("%d%d", &a, &b); // char* aux = malloc(sizeof(char)*sizeof(a)) apoi interschimbare
                         // asta in macro

}