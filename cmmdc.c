#include <stdio.h>
#include <stdarg.h>
#define NMAX 100

void cmmdc (int n, ...) {
	va_list args;

	va_start (args, n);

	int v[NMAX];
	int cmm, a, b;

    for (int i = 0; i < n; ++i) {
    	v[i] = va_arg(args, int);
    }

    for (int i = 1; i < n; ++i) {
    	int c;

    	a = v[i - 1];
    	b = v[i];
	
    	while (b) {
        	c = a % b;
        	a = b;
       		b = c;
    	}
	
   		cmm = v[i] = a;
   	}

    printf("%d\n", cmm);

	va_end(args);
}

int main() {

	cmmdc(3, 4, 8, 16);

}