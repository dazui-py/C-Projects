#include <__stdarg_va_list.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdarg.h>
#include <sys/types.h>

int sum(int p_qty, ...) {
	va_list args;
	va_start(args, p_qty);
	
	int s = 0;
	for (int i = 0; i < p_qty; i++) {
		int x = va_arg(args, int);
		s+=x;
	}
	va_end(args);
	return s;
}

int sum2(int a, ...) {
	va_list args;
	va_start(args, a);

	int s = a;
	int x = va_arg(args, int);

	while (x != 0) {
		s += x;
	}

	va_end(args);
	return s;
}

int main(int argc, char *argv[]) {
	printf("Sum is: %d\n", sum(4, 1, 2, 3, 4));
	return 0;
}
