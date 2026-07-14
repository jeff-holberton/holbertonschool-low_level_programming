#include "main.h"
/**
 * string_toupper - function that converts lower case
 * characters in a string to upper
 * @s: first
 *
 * Return: returns a char pointer to the converted string
*/
char *string_toupper(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = s[i] - 32;
		i++;
	}
	return (&(*s));
}
