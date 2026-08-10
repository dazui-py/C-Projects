#include <stdarg.h>
// #include <stdio.h>

int my_scanf(const char *fmtS, ...);
char *my_strcpy(char *dest, const char* src);

int main(){
	char x[] = "Lorem Ipsum\n";
	my_scanf("%s", &x, "Ipsum Lorem\n");
	// printf("x: %s", x);

	return 0;
}

char *my_strcpy(char *dest, const char* src){
	int i = 0;
	for (; src[i] != '\0'; i++) {
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return dest;
}

int my_scanf(const char *fmtS, ...){
	va_list args;

  for (va_start(args, fmtS); *fmtS != '\0'; fmtS++){
		if (*fmtS == '%') {
			fmtS++;
			if (*fmtS == 'd') {
				int *input = va_arg(args, int*);
				int output = va_arg(args, int);
				*input = output;
			}
			if (*fmtS == 'c') {
				char *input = (char*)va_arg(args, int*);
				char output = (char)va_arg(args, int);
				*input = output;
			}
			if (*fmtS == 's') {
				my_strcpy(va_arg(args, char*), va_arg(args, char*));
			}
		}
	}
	va_end(args);
	return 0;
};
