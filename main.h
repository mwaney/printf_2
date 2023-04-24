#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#define BUFFER_SIZE 1024

/**
 * struct conv_spec - Struct  to handle specifiers
 * @specifier: The conversion specifier
 * @print_spec: The corresponding function to print the specifier
 */
typedef struct conv_spec
{
	char specifier;
	int (*print_spec)(va_list, char *, int);
} conv_spec;

int _printf(const char *format, ...);

int handle_specifier(va_list argList, char *buffer, int buff_ind,
		conv_spec *spec_arr, char specifier, int *count);
int handle_char(char *buffer, int buff_ind, char c, int *count);
int handle_buffer(char *buffer, int *buff_ind);


int print_character(va_list argList, char *buffer, int buff_ind);
int print_string(va_list argList, char *buffer, int buff_ind);
int print_percent(va_list argList, char *buffer, int buff_ind);

#endif
