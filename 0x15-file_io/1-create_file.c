#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/**
 * create_file - Creates a file.
 * @filename: A pointer to the name of the file to create.
 * @text_content: A pointer to a string to write to the file.
 *
 * Return: If the function fails - -1.
 *         Otherwise - 1.
 */

int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t res;

	if (filename == NULL)
	return (-1);

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);

	if (fd == -1)
	return (-1);

	if (text_content != NULL)
	{
		size_t len = strlen(text_content);
		char *buf = malloc(len + 1);

		if (buf == NULL)
		{
			close(fd);
			return (-1);
		}

		strcpy(buf, text_content);

		res = write(fd, buf, len);

		free(buf);

		if (res == -1 || (size_t)res != len)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
