#include "main.h"

/**
 * get_bit - Gets the value of a bit at a given index.
 * @n: Bit.
 * @index: Index to get the value at - indices start at 0.
 *
 * Return: If an error occurs - -1.
 *         Otherwise - The value of bit at index.
*/
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= 8 * sizeof(unsigned long int))
	return (-1);

	return ((n >> index) & 1);
}
