#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * _puts_recursion - function that prints a string
 * @s: string to print
 */
void _puts_recursion(char *s)
{
	int i = 0;

	if (s[i] == '\0')
	{
		_putchar('\n');
		return;
	}
	_putchar(s[i]);
	_puts_recursion(&(s[i + 1]));
}
