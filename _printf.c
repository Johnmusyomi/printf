#include "main.h"

void print_buffer(char buffer[], int *buffer_index);

/**
 *	_printf - function that produces output according to a format.
 *	@format: format
 *
 *	Return: printed chars
*/
int _printf(const char *format, ...)
{
	int index, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buffer_index = 0;
	va_list list;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (index = 0; format && format[index] != '\0'; index++)
	{
		if (format[index] != '%')
		{
			buffer[buffer_index++] = format[index];
			if (buffer_index == BUFFER_SIZE)
				print_buffer(buffer, &buffer_index);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buffer_index);
			flags = get_flags(format, &index);
			width = get_width(format, &index, list);
			precision = get_precisin(format, &index, list);
			size = get_size(format, &index);
			++index;
			printed = handle_print(format, &index, list, buffer, flags,
					width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
	printed_buffer(buffer, &buffer_index);
	va_end(list);

	return (printed_chars);
}

/**
 *	print_buffer - Prints the contents of the buffer if it exist
 *	@buffer: Array of chars
 *	@buffer_index: Index at which to add next char, represents the length.
*/
void print_buffer(char buffer[], int *buffer_index)
{
	if (buffer_index > 0)
		write(1, &buffer[0], *buffer_index);
	*buffer_index = 0;
}
