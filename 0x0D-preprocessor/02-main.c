#include <stdio.h>

/**
 * main - Prints the name of the file a program was compiled from,
 *        followed by a new line.
 *
 * Return: Always 0.
 */
int main(void)
{
        printf("%s\n", __FILE__);

        return (0);
}
