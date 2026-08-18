#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * _pow_recursion - function that calculates x at the power
 * of y
 * @x: number to calculate
 * @y: power
 *
 * Return: x to the power of y
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	if (x == 0)
		return (0);
	return (x * _pow_recursion(x, y - 1));
}
