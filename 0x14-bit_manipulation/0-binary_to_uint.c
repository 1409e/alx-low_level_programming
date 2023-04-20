#include "main.h"
#include <string.h>
#include <stddef.h>

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: A pointer to a string of 0 and 1 chars.
 *
 * Return: If b is NULL or contains chars not 0 or 1 - 0.
 *         Otherwise - the converted number.
*/
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	unsigned int bit = 1;

	if (b == NULL)
		return (0);

	while (b[bit])
	{
		if (b[bit] != '0' && b[bit] != '1')
			return (0);

		bit++;
	}

	while (bit--)
	{
		if (b[bit] == '1')
			result += 1 << (strlen(&b[bit]) - 1);
	}

	return (result);
}
