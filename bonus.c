#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void show_value(const char *str, ...) {
	int n;
	void *x;

	va_list args;
	va_start(args, str);

	for (int i = 0; i < strlen(str); ++i) {
		if (str[i] == '%') {
			
			if (str[i + 1] == 'd') {
				printf("%d", va_arg(args, int));
			}

			if (str[i + 1] == 'f') {
				printf("%f", va_arg(args, double));
			}

			if (str[i + 1] == 'c') {
				printf("%c", va_arg(args, int));
			}
		} else {
			if (str[i - 1] != '%') {
				printf("%c", str[i]);
			}
		}
	}
}

int main() {

	int x = 2; float y = 2.2; char s = 'A';
	show_value("%d %f %c\n", x, y, s);
}