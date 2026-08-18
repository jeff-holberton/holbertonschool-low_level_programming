#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * guess - function that checks if n is divisible by g
 * @n: target number
 * @g: each guess
 *
 * Return: 1 if number is prime, 0 if not
 */
int guess(int n, int g)
{
	if (g >= n)
		return (1);
	if (n % g == 0)
	{
		return (0);
	}
	return (guess(n, g + 1));
}
/**
 * is_prime_number - function that checks if a number is prime
 * @n: number to check
 *
 * Return: 1 if prime, 0 if not
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (guess(n, 2));
}
