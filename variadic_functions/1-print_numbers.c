#include <stdlib.h>
#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * print_numbers - function that prints an n number of numbers passed
 * as arguments, separated by a character
 * @separator: first
 * @n: second
 * @...: third
*/
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i = 0;

	if (separator == NULL)
		return;
	va_start(args, n);
	while (i < n)
	{
		printf("%d", va_arg(args, int));
		i++;
		if (i != n)
		{
			printf("%s", separator);
		}
	}
	printf("\n");
	va_end(args);
}
