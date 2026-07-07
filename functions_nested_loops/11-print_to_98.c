#include <stdio.h>
#include "main.h"
/**
 * print_to_98 - function that prints form n to 98
 * @n: first operand
 *
 * Return: return is void
*/
void print_to_98(int n)
{
	if (n < 98)
	{
		while (n <= 98)
		{
			printf("%d, ", n);
			n++;
		}
		printf("\n");
	}
	else if (n == 98)
	{
		printf("%d\n", n);
	}
	else
	{
		while (n >= 98)
		{
			printf("%d, ", n);
			n--;
		}
		printf("\n");
	}
}
