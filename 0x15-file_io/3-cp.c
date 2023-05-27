#include "main.h"
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

/**
 * main - Copies the content of a file to another file.
 * @argc: Number of arguments.
 * @argv: Array of arguments.
 *
 * Return: 0 if successful, otherwise error code.
*/
int main(int argc, char *argv[])
{
	int fd_from, fd_to, ret;
	ssize_t bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
	{
		fprintf(stderr, "Usage: cp file_from file_to\n");
		return (97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		fprintf(stderr, "Error: Can't read from file %s\n", argv[1]);
		return (98);
	}

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_to == -1)
	{
		fprintf(stderr, "Error: Can't write to %s\n", argv[2]);
		return (99);
	}

	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written != bytes_read)
		{
			fprintf(stderr, "Error: Write to %s failed\n", argv[2]);
			close(fd_from);
			close(fd_to);
			return (99);
		}
	}

	if (bytes_read == -1)
	{
		fprintf(stderr, "Error: Can't read from file %s\n", argv[1]);
		close(fd_from);
		close(fd_to);
		return (98);
	}

	ret = close(fd_from);
	if (ret == -1)
	{
		fprintf(stderr, "Error: Can't close fd %d\n", fd_from);
		close(fd_to);
		return (100);
	}

	ret = close(fd_to);
	if (ret == -1)
	{
		fprintf(stderr, "Error: Can't close fd %d\n", fd_to);
		return (100);
	}

	return (0);
}
