#include "main.h"
/**
 * cap_string - function that capitalizes all starting letters
 * of words of a string
 * @s: first operand
 *
 * Return: returns a char pointer to the converted string
*/
char *cap_string(char *s)
{
	int i = 0;
	int c = 0;
	int exit_loop = 0;
	char sep[] = " \t\n,;.!?\"(){}";

	while (s[i] != '\0')
	{
		if (i == 0 && (s[i] >= 'a' && s[i] <= 'z'))
		{
			s[i] = s[i] - 32;
		}
		else if (s[i] >= 'a' && s[i] <= 'z')
		{
			c = 0;
			exit_loop = 0;
			while (sep[c] != '\0' && exit_loop != 1)
			{
				if (sep[c] == s[i - 1])
				{
					s[i] = s[i] - 32;
					exit_loop = 1;
				}
				c++;
			}
		}
		i++;
	}
	return (&(*s));
}
