#include <stdlib.h>
#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * sum_them_all - function that sums an n number
 * of integers in a variadic function
 * @n: first
 * @...: second
 *
 * Return: returns sum
*/
int sum_them_all(const unsigned int n, ...)
{
	va_list args;
	unsigned int i = 0;
	int sum = 0;
	int temp;

	va_start(args, n);
	while (i < n)
	{
		temp = va_arg(args, int);
		sum = sum + temp;
		i++;
	}
	va_end(args);
	return (sum);
}
