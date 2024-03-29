#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * clear_bit - Sets the value of a bit at a given index to 0.
 * @n: Pointer to the bit.
 * @index: Index to set the value at - indices start at 0.
 *
 * Return: If an error occurs - -1.
 *         Otherwise - 1.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
	{
		fprintf(stderr, "Error: invalid index %u\n", index);
		return (-1);
	}

	*n &= ~(1UL << index);
	return (1);
}
