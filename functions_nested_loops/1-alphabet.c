#include "main.h"
/**
 * print_alphabet - function that prints the alphabet
 * in lower case, followed by a new line
 * Return: returns 0
*/
void print_alphabet(void)
{
	int n;

	for (n = 97 ; n < 123 ; n++)
	{
		_putchar(n);
	}
	_putchar('\n');
}
