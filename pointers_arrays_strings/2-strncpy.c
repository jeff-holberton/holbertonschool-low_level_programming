#include "main.h"
/**
 * _strncpy - function that copies a string into another
 * @dest: first
 * @src: second
 * @n: third
 *
 * Return: returns a char pointer to destination string
*/
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (&(*dest));
}
