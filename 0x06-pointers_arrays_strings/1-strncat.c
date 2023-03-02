#include "main.h"

/**
 * _strncat - Concatenates two strings.
 * @dest: String to be appended upon.
 * @src: String to be appended.
 * @n:Number of bytes to be appended from src to dest.
 *
 * Return: A pointer to dest.
 */
char *_strncat(char *dest, char *src, int n)
{
	int index = 0, dest_len = 0;

	while (dest[index++])
		dest_len++;

	for (index = 0; src[index] && index < n; index++)
		dest[dest_len++] = src[index];

	return (dest);
}
