#include <stdlib.h>
#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * print_strings - function that prints an n number of strings passed
 * as arguments, separated by a character
 * @separator: first
 * @n: second
 * @...: third
*/
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i = 0;
	char *temp;

	va_start(args, n);
	while (i < n)
	{
		temp = va_arg(args, char*);
		if (temp == NULL)
			printf("nil");
		else
			printf("%s", temp);
		i++;
		if (separator != NULL && i < n)
			printf("%s", separator);
	}
	printf("\n");
	va_end(args);
}
