#include "main.h"
/**
 * _isdigit - function that checks if given character is a digit
 * @c: first operand
 *
 * Return: returns 1 if true, 0 if not
*/
int _isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}

