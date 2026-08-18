#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * _print_rev_recursion - function that prints a string
 * in reverse
 * @s: string to print
 */
void _print_rev_recursion(char *s)
{
	int i = 0;

	if (s[i] == '\0')
	{
		return;
	}
	_print_rev_recursion(&(s[i + 1]));
	_putchar(s[i]);
}
