#include "main.h"
/**
 * _memset - function that sets n bytes of strin s
 * to char b
 * @s: first
 * @b: second
 * @n: third
 *
 * Return: returns a char pointer to modified string
*/
char *_memset(char *s, char b, unsigned int n)
{
	int i = 0;

	while (i < n)
	{
		s[i] = b;
		i++;
	}
	return (&(*s));
}
