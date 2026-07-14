#include "main.h"
/**
 * _strlen - function that returns the length of an array
 * @s: first operand
 *
 * Return: returns length of array
*/
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}
