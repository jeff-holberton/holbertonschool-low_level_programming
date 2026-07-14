#include "main.h"
/**
 * rev_string - function that reverses a string
 * @s: first operand
*/
void rev_string(char *s)
{
	char temp;
	int a = 0;
	int b = 0;

	while (s[a] != '\0')
	{
		a++;
	}
	a--;
	while (a > b)
	{
		temp = s[a];
		s[a] = s[b];
		s[b] = temp;
		a--;
		b++;
	}
}
