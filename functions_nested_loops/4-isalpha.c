#include "main.h"
/**
 * _isalpha - function that checks if a character is a letter
 * @c: first operand
 *
 * Return: returns 1 if is a letter, 0 if not
*/
int _isalpha(int c)
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123))
		return (1);
	else
		return (0);
}
