#include "main.h"
#include <stdlib.h>
/**
 * _strstr - function that searches string haystack for
 * a perfect match of substring needle
 * @haystack: first
 * @needle: second
 *
 * Return: returns pointer to start of match, NULL if nothing is found
*/
char *_strstr(char *haystack, char *needle)
{
	int i = 0;
	int n = 0;
	int match = 0;

	while (haystack[i] != '\0')
	{
		n = 0;
		while ((haystack[i] == needle[n]) && (needle[n] != '\0'))
		{
			if (n == 0)
				match = i;
			n++;
			i++;
		}
		if (needle[n] == '\0')
			return (&(haystack[match]));
		i = i + 1 - n;
	}
	return (NULL);
}

