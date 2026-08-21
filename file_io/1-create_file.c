#include "main.h"
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <fcntl.h>
/**
 * create_file - function that creates a file, writes content
 * to it, will truncate if already exits
 * @filename: file to create
 * @text_content: text to write
 *
 * Return: -1 if failed, 1 if successful
 */
int create_file(const char *filename, char *text_content)
{
	int file_descriptor;
	int length = 0;

	if (!filename)
		return (-1);
	file_descriptor = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);
	if (file_descriptor < 0)
		return (-1);
	if (text_content != NULL)
	{
		while (text_content[length])
			length++;
		if (length > 0)
			length--;
		if (write(file_descriptor, text_content, length) < 0)
		{
			close(file_descriptor);
			return (-1);
		}
	}
	close(file_descriptor);
	return (1);
}
