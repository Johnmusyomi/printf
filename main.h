#ifndef main_h
#define main_h
#include <stdarg.h>
#include <stdio.h>
#include <unist.h>

#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_LONG 1


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
int handle_print(const char *fmt, int *i, va_list list,
		char buffer[], int flags, int width, int precision, int size);

/* FUNCTIONS */
int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size);

int handle_write_char(char c, char buffer[],
		int flags, int width, int precision, int size);

int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *, va_list list);
int get_size(const char *format, int *i);

int is_printable(char);

#endif
