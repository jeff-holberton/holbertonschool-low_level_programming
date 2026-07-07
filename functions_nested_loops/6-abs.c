#include "main.h"
/**
 * _abs - returns absolute value of an integer
 * @n: first operand
 *
 * Return: returns value of n
*/
int _abs(int n)
{
	if (n < 0)
		n = n * -1;
	return (n);
}
