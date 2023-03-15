#include "main.h"

/**
 * _isalpha - Checks if a character is alphabetic.
 * @c: Character
 *
 * Return: 1 if character is letter, lowercase or uppercase, 0 if not.
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
