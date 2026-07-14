#include "main.h"
/**
 * rev_string - function that reverses a string
 * @s: first operand
*/
void rev_string(char *s)
{
	char *temp;
	int a = 0;
	int b = 0;

	while (s[a] != '\0')
	{
		temp[a] = s[a];
		a++;
	}
	while (--a >= 0)
	{
		s[b] = temp[a];
		b++;
	}
}
