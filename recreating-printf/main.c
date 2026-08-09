#include <__stdarg_va_list.h>
#include <stdarg.h>
#include <unistd.h>

void my_putchar(char c);

int my_printf(const char *str, ...);

void putint(int n);

void string_print(char *strings);

int main() {
	my_printf("Hello, %d World! %s", 123, "test");
}

void my_putchar(char c){
	write(1, &c, 1);
}

void putint(int n){
	if (n == -2147483648) {
		write(1, "-2147483648", 11);
		return;
	}
	if (n < 0) {
		write(1, "-", 11);
		n = -n;
	}
	
	if (n / 10 != 0) {
		putint(n / 10);
	}

	char c = (n % 10) + '0';
	write(1, &c, 1);

}

void string_print(char *strings){
	while(*strings != '\0'){
		my_putchar(*strings);
		strings++;
	}
}

int my_printf(const char *str, ...){
	va_list args;

	for (va_start(args, str); *str != '\0'; str++){
	 if (*str == '%') {
		 str++;
		 if (*str == 'c') {
			my_putchar((char)va_arg(args, int));
		 }
		 if (*str == 'd') {
			putint(va_arg(args, int));
		 }
		 if (*str == 's') {
			string_print(va_arg(args, char*));
		 }
	 }
		else {
			my_putchar(*str);
		}
	}
	va_end(args);
	return 0;
}
