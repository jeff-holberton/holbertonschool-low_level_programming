#include "main.h"
/**
 * print_alphabet_X10 - function prints alphabet
 * lower case 10 times, followed by a new line
 * Return: return is void
*/
void print_alphabet_X10(void)
{
	int i = 0;

	while (i < 11)
	{
		int n;

		for (n = 97 ; n < 123 ; n++)
		{
			_putchar(n);
		}
		i++;
	}
	_putchar('\n');
}
