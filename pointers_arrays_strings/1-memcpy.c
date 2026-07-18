#include "main.h"
/**
 * _memcpy - function that copies n bytes of strin src
 * into string dest
 * @dest: first
 * @src: second
 * @n: third
 *
 * Return: returns a char pointer to modified string
*/
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (&(*dest));
}
