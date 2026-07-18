#include "main.h"
#include <stdlib.h>
/**
 * _strchr - function that locates a character
 * in a string
 * @s: first
 * @c: second
 *
 * Return: returns a char pointer to first occurence of ,NULL if not
*/
char *_strchr(char *s, char c)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	if (s[i] == c)
		return (&s[i]);
	return (NULL);
}
