#include "main.h"


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

int handle_char(char *buffer, int buff_ind, char c, int *count)
{
	buffer[buff_ind++] = c;
	*count += 1;
	return (buff_ind);
}
int handle_buffer(char *buffer, int *buff_ind)
{
	int count;

	write(1, buffer, *buff_ind);
	count = *buff_ind;
	*buff_ind = 0;
	return (count);
}
