#include <stdio.h>

	
int euclid(int a, int b)
	
{
	
    int c;
	
    while (b) {
	
        c = a % b;
	
        a = b;
	
        b = c;
	
    }
	
    return a;
	
}

int main() {
	printf("%d\n", euclid(4, 12));
}