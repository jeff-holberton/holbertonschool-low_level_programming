#include "main.h"
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <fcntl.h>
/**
 * main - program that copies the content of a file to a
 * new one
 * @ac: argument count
 * @av: argument array
 *
 * Return: 0
 */
int main(int ac, char **av)
{
	int to_descriptor, from_descriptor, bytes_read;
	char buffer[1024];

	if (ac != 3)
	{
		dprintf(2, "Usage: cp file_from file_to\n");
		exit(97);
	}
	from_descriptor = open(av[1], O_RDONLY);
	if (from_descriptor < 0)
	{
		dprintf(2, "Can't read from %s\n", av[1]);
		exit(98);
	}
	to_descriptor = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (to_descriptor < 0)
	{
		dprintf(2, "Can't write to %s\n", av[2]);
		exit(99);
	}
	while ((bytes_read = read(from_descriptor, buffer, 1024)) > 0)
	{
		write(to_descriptor, buffer, bytes_read) < 0)
		{
			dprintf(2, "Can't write to %s\n", av[2]);
			exit(99);
		}
	}
	if (close(to_descriptor) < 0)
	{
		dprintf(2, "Error: Can't close fd %d", to_descriptor);
		exit(100);
	}
	if (close(from_descriptor) < 0)
	{
		dprintf(2, "Error: Can't close fd %d", from_descriptor);
		exit(100);
	}
	return (0);
}
