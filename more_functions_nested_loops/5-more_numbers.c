#include "main.h"
/**
 * more_numbers - function that prints numbers 0-14
 * 10 times, followed by a new line
 *
 * Return: return is void
*/
void more_numbers(void)
{
	int n;
	int i;

	for (i = 0 ; i < 10 ; i++)
	{
		for (n = 0 ; n < 15 ; n++)
		{
			if (n > 9)
			{
				_putchar(n / 10 + '0');
			}
			_putchar(n % 10 + '0');
		}
		_putchar('\n');
	}
}
