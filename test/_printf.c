#include "main.h"

/**
 * _printf - Prints a formatted string to the standard output.
 * @format: A string.
 * Return:  number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list argList;
	int count = 0, buff_ind = 0, i;
	char buffer[BUFFER_SIZE];
	conv_spec spec_arr[] = 
	{
		{'c', print_character},
		{'s', print_string},
		{'%', print_percent},
		{'\0', NULL}
	};

	va_start(argList, format);
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			buff_ind = handle_specifier(argList, buffer, buff_ind, spec_arr,
					format[i], &count);
		}
		else
			buff_ind = handle_char(buffer, buff_ind, format[i], &count);
		if (buff_ind >= BUFFER_SIZE - 1)
			count += handle_buffer(buffer, &buff_ind);
	}
	count += handle_buffer(buffer, &buff_ind);
	va_end(argList);
	return (count);
}
