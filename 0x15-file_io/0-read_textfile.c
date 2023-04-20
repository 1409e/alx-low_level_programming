#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: the name of the file to read
 * @letters: the number of letters to read and print
 *
 * Return: the actual number of letters read and printed,
 *         0 if filename is null.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t bytes_read, bytes_written;
	char c;

	if (filename == NULL)
	return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	return (0);

	bytes_read = 0;
	while (bytes_read < (int)letters && read(fd, &c, 1) == 1)
	{
		bytes_written = write(STDOUT_FILENO, &c, 1);
		if (bytes_written == -1 || bytes_written != 1)
	{
		close(fd);
		return (0);
	}
		bytes_read++;
	}

	close(fd);

	return (bytes_read);
}
