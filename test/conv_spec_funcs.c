#include "main.h"
int reverse_buffer(char *buffer, int start, int end);
/**
 * print_character - prints a character to a buffer
 * @argList: list of arguments
 * @buffer: pointer to buffer to store output
 * @buff_ind: current index of buffer
 * Return: index of buffer
 */
int print_character (va_list argList, char *buffer, int buff_ind)
{
	char c = va_arg(argList, int);
	buffer[buff_ind] = c;
	return (buff_ind + 1);
}

/**
 * print_string - prints a string to a buffer
 * @argList: list of arguments
 * @buffer: pointer to buffer to store output
 * @buff_ind: current index of buffer
 * Return: index of buffer
 */
int print_string(va_list argList, char *buffer, int buff_ind)
{
	char *string = va_arg(argList, char *);
	int i = 0;

	if (string == NULL)
		string = "(null)";

	while (string[i])
	{
		buffer[buff_ind++] = string[i];
		i++;
	}
	return (buff_ind);
}

/**
 * print_percent - prints a percent character to a buffer
 * @argList: list of arguments
 * @buffer: pointer to buffer to store output
 * @buff_ind: current index of buffer
 * Return: index of buffer
 */
int print_percent(va_list argList, char *buffer, int buff_ind)
{
	(void) argList;
	buffer[buff_ind] = '%';
	return (buff_ind + 1);
}
