#include "main.h"
/**
 * print_diagonal - function that prints the character
 * \ , n times in a diagonal
 * @n: first operand
 *
 * Return: return is void
*/
void print_diagonal(int n)
{
	int i;
	int s;

	for (i = 0 ; i < n ; i++)
	{
		if (i > 0)
		{
			_putchar('\n');
			for (s = 0 ; s < i; s++)
			{
				_putchar(32);
			}
		}
		_putchar(92);
	}
	_putchar('\n');
}

