#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * _strlen_recursion - function that returns the length
 * of a string
 * @s: string to print
 *
 * Return: returns length
 */
int _strlen_recursion(char *s)
{
	if (!s)
		return (0);
	if (s[0] == '\0')
		return (0);
	return (1 + _strlen_recursion(&s[1]));
}
