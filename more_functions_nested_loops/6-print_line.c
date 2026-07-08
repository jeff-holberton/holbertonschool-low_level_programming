#include "main.h"
/**
 * print_line - function that prints the character
 * _ , n times
 * @n: first operand
 *
 * Return: return is void
*/
void print_line(int n)
{
	int i;

	for (i = 0 ; i < n ; i++)
	{
		_putchar('_');
	}
	_putchar('\n');
}
