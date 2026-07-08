#include "main.h"
/**
 * _isupper - function that checks if given character is uppercase
 * @c: first operand
 *
 * Return: returns 1 if true, 0 if not
*/
int _isupper(int c)
{
	if (c > 64 && c < 91)
		return (1);
	else
		return (0);
}
