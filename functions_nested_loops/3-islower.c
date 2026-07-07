#include "main.h"
/**
 * _islower - function checks if the passed character is
 * lowercase
 * @c: first operand
 *
 * Return: returns 1 if lowercase, 0 if not
*/
int _islower(int c)
{
	if (c > 96 && c < 123)
		return (1);
	else
		return (0);
}
