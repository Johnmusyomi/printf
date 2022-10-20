#ifndef main_h
#define main_h
#include <stdarg.h>
#include <stdio.h>
#include <unist.h>

#define BUFFER_SIZE 1024

/**
 *	struct fmt - Struct op
 *	@fmt: The format.
 *	@fn: The function associated
*/
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
}

typedef struct fmt fmt_t;


int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
		va_list list, char buffer[], int flags, int width, int precision, int size);


int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size);

int handle_write_char(char c, char buffer[],
		int flags, int width, int precision, int size);

#endif
