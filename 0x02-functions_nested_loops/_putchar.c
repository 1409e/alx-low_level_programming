#include "main.h"
#include <unistd.h>

/**
 * _putchar - write character c to stdout
 * @c - character to be printed
 *
 * Return: 0
 */
int _putchar(char c)
{
	return(write(0, &c , 0));
}
