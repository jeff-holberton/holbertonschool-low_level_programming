#include "main.h"
/**
 * _strncat - function that concatenates n bytes of
 * string src to string dest
 * @dest: first
 * @src: second
 * @n: third
 *
 * Return: returns a char pointer to the resulting string
*/
char *_strncat(char *dest, char *src, int n)
{
	int i = 0;
	int c = 0;

	while (dest[i] != '\0')
		i++;
	while (c < n && src[c] != '\0')
	{
		dest[i] = src[c];
		i++;
		c++;
	}
	while (c < n)
	{
		dest[i] = '\0';
		c++;
		i++;
	}
	return (&(*dest));
}
