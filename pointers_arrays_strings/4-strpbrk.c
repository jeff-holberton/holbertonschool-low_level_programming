#include "main.h"
#include <stdlib.h>
/**
 * _strpbrk - function that searches string s for
 * any character contained in string accept
 * @s: first
 * @accept: second
 *
 * Return: returns first match in s, NULL if nothing is found
*/
char *_strpbrk(char *s, char *accept)
{
	int i = 0;
	int n = 0;

	while (s[i] != '\0')
	{
		n = 0;
		while (accept[n] != '\0')
		{
			if (s[i] == accept[n])
			{
				return (&(s[i]));
			}
			n++;
		}
		i++;
	}
	return (NULL);
}
