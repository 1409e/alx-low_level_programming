#include "main.h"
#include <stdlib.h>

/**
 * print_binary - Prints the binary representation of a number.
 * @n: Number to be printed in binary.
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1;
	int i, flag = 0;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	for (i = (sizeof(unsigned long int) * 8) - 1; i >= 0; i--)
	{
		if ((n & (mask << i)) && !flag)
			flag = 1;
		if (flag)
			((n & (mask << i)) ? _putchar('1') : _putchar('0'));
	}
}
