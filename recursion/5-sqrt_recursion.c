#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * guess - function that guesses square root
 * @n: number to calculate
 * @g: guess
 *
 * Return: returns guess
 */
int guess(int n, int g)
{
	if (g * g == n)
		return (g);
	if (g * g > n)
		return (-1);
	return (guess(n, g + 1));
}
/**
 * _sqrt_recursion - function that calculates the square root
 * of a number
 * @n: number to calculate
 *
 * Return: square root of n
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0 || n == 1)
		return (n);
	return (guess(n, 1));
}
