#include "main.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * set_bit - Sets the value of a bit at a given index to 1.
 * @n: A pointer to the bit.
 * @index: The index to set the value at - indices start at 0.
 *
 * Return: If an error occurs - -1.
 *         Otherwise - 1.
*/
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int *tmp;

	if (n == NULL)
	return (-1);

	tmp = malloc(sizeof(unsigned long int));
	if (tmp == NULL)
	return (-1);

	*tmp = 1 << index;
	*n |= *tmp;

	free(tmp);
	return (1);
}
