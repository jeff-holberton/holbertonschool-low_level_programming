#include "main.h"
/**
 * leet - function that returns an encoded string
 * @s: first
 *
 * Return: returns char pointer to encoded string
*/
char *leet(char *s)
{
	char letters[] = "aAeEoOtTlL";
	char numbers[] = "4433007711";
	int i = 0;
	int comp = 0;

	while (s[i] != '\0')
	{
		comp = 0;
		while (letters[comp] != '\0')
		{
			if (s[i] == letters[comp])
			{
				s[i] = numbers[comp];
				break;
			}
			comp++;
		}
		i++;
	}
	return (&(*s));
}
