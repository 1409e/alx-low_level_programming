#include "main.h"
#include <stdlib.h>

/**
 * get_endianness - Checks endianness.
 *
 * Return: If big-endian - 0.
 *         If little-endian - 1.
*/
int get_endianness(void)
{
	char *byte_ptr;
	int *int_ptr;
	int result;

	int_ptr = malloc(sizeof(int));

	*int_ptr = 1;

	byte_ptr = (char *)int_ptr;
	result = byte_ptr[0] == 1;

	free(int_ptr);

	return (result);
}
