#include "main.h"
/**
 * print_triangle - function that prints a triangle
 * of size 'size' using the character #
 * @size: first operand
 *
 * Return: return is void
*/
void print_triangle(int size)
{
	int row, col;

	for (row = 1 ; row <= size ; row++)
	{
		for (col = size ; col > 0 ; col--)
		{
			if (col <= row)
			{
				_putchar('#');
			}
			else
			{
				_putchar(' ');
			}
		}
		_putchar('\n');
	}
	if (size < 1)
		_putchar('\n');
}
