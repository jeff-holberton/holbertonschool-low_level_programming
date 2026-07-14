#include "main.h"
/**
 * puts2 - function that prints every second character of a string
 * @str: first operand
*/
void puts2(char *str)
{
	int i = 0;

	while (str[i] != '\0' && str[i-1] != '\0')
	{
		_putchar(str[i]);
		i = i + 2;
	}
	_putchar('\n');
}
