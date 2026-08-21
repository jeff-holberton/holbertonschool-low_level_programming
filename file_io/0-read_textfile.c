#include "main.h"
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <fcntl.h>
/**
 * read_textfile - function that reads a certain amount of
 * letters from a textfile, and prints them to stdout
 * @filename: file to read
 * @letters: amount of bytes to read
 *
 * Return: returns the number of bytes printed or 0 if failed
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_descriptor;
	ssize_t printed;
	char *buffer;

	if (!filename || letters == 0)
		return (0);
	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (0);
	buffer = malloc(letters);
	if (!buffer)
	{
		close(file_descriptor);
		return (0);
	}
	printed = read(file_descriptor, buffer, letters);
	if (printed < 0)
	{
		free(buffer);
		close(file_descriptor);
		return (0);
	}
	if (write(STDOUT_FILENO, buffer, printed) < 0)
	{
		free(buffer);
		close(file_descriptor);
		return (0);
	}
	free(buffer);
	close(file_descriptor);
	return (printed);
}
