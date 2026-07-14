#include "main.h"
/**
 * puts_half - function that prints the second half of a string
 * @str: first operand
*/
void puts_half(char *str)
{
	int a = 0;

	while (str[a] != '\0')
	{
		a++;
	}
	if (a % 2 == 0)
	{
		a = a / 2;
		while (str[a] != '\0')
		{
			_putchar(str[a]);
			a++;
		}
	}
	else
	{
		a = (a + 1) / 2;
		while (str[a] != '\0')
		{
			_putchar(str[a]);
			a++;
		}
	}
	_putchar('\n');
}
