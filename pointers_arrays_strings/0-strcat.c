#include "main.h"
/**
 * _strcat - function that concatenates two strings
 * @dest: first
 * @src: second
 *
 * Return: returns char pointer to destination string
*/
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int c = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[c] != '\0')
	{
		dest[i] = src[c];
		i++;
		c++;
	}
	dest[i] = '\0';
	return (&(*dest));
}
