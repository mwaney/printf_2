#include "main.h"

/**
 * handle_specifier - Processes a conversion specifier and writes the
 *                    corresponding string representation to a buffer.
 * @argList: A va_list containing the arguments for the conversion specifier.
 * @buffer: A character array representing the output buffer.
 * @buff_ind: The current index of the buffer.
 * @spec_arr: An array of conversion specifiers
 * @specifier: The conversion specifier character to process.
 * @count: A pointer to an integer
 * Return: The updated index of the buffer.
 */
int handle_specifier(va_list argList, char *buffer, int buff_ind,
		conv_spec *spec_arr, char specifier, int *count)
{
	int j;

	for (j = 0; spec_arr[j].specifier != '\0'; j++)
	{
		if (spec_arr[j].specifier == specifier)
		{
			buff_ind = spec_arr[j].print_spec(argList, buffer, buff_ind);
			if (buff_ind >= BUFFER_SIZE - 1)
				*count += handle_buffer(buffer, &buff_ind);
			break;
		}
	}
	if (spec_arr[j].specifier == '\0')
	{
		buff_ind = handle_char(buffer, buff_ind, '%', count);
		buff_ind = handle_char(buffer, buff_ind, specifier, count);
		if (buff_ind >= BUFFER_SIZE - 1)
			*count += handle_buffer(buffer, &buff_ind);
	}
	return (buff_ind);
}

/**
 * handle_char - Writes a single character to a buffer.
 * @buffer: A character array representing the output buffer.
 * @buff_ind: The current index of the buffer.
 * @c: The character to write to the buffer.
 * @count: A pointer to an integer
 * Return: The updated index of the buffer.
 */
int handle_char(char *buffer, int buff_ind, char c, int *count)
{
	buffer[buff_ind++] = c;
	*count += 1;

	if (buff_ind >= BUFFER_SIZE - 1)
	{
		handle_buffer(buffer, &buff_ind);
	}

	return (buff_ind);
}
/**
 * handle_buffer - Writes the contents of a buffer to the standard output.
 * @buffer: A character array representing the output buffer.
 * @buff_ind: current index of the buffer.
 * Return: The number of characters written to the standard output.
 */
int handle_buffer(char *buffer, int *buff_ind)
{
	int count = *buff_ind;

	if (count > 0)
	{
	write(1, buffer, count);
	count = *buff_ind;
	*buff_ind = 0;
	}
	return (count);
}
