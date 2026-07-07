#include "main.h"
/**
 * times_table - prints the time tables from 1-9
 *
 * Return: returns void
*/
void times_table(void)
{
	int n1;
	int n2;

	for (n1 = 0 ; n1 < 10 ; n1++)
	{
		for (n2 = 0 ; n2 < 10 ; n2++)
		{
			int m = n1 * n2;

			if (m > 9)
				_putchar(m / 10 + '0');
			else
				_putchar(32);
			_putchar(m % 10 + '0');
			if (n2 != 9)
				_putchar(44);
			_putchar(32);
		}
		_putchar('\n');
	}
}
