#include "main.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * set_bit - Sets the value of a bit at a given index to 1.
 * @n: Pointer to the bit.
 * @index: Index to set the value at - indices start at 0.
 *
 * Return: If an error occurs - -1.
 *         Otherwise - 1.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (n == NULL || index >= sizeof(unsigned long int) * 8)
		return (-1);

	*n |= (1UL << index);
	return (1);
}
