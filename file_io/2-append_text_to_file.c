#include "main.h"
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <fcntl.h>
/**
 * append_text_to_file - function that appends a file with
 * a given string
 * @filename: file to append
 * @text_content: text to write
 *
 * Return: -1 if failed, 1 if successful
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor;
	int length = 0;

	if (!filename)
		return (-1);
	file_descriptor = open(filename, O_WRONLY | O_APPEND);
	if (file_descriptor < 0)
		return (-1);
	if (text_content)
	{
		while (text_content[length])
			length++;
		write(file_descriptor, text_content, length);
	}
	close(file_descriptor);
	return (1);
}
