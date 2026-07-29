#include <stdio.h>
#include "3-calc.h"
/* op_add - function that adds
 * @a: first
 * @b: second
 *
 * Return: returns a+b
*/
int op_add(int a, int b)
{
	return (a + b);
}

/* op_sub - function that subtracts
 * @a: first
 * @b: second
 *
 * Return: returns a-b
*/
int op_sub(int a, int b)
{
	return (a - b);
}

/* op_mul - function that multiplies
 * @a: first
 * @b: second
 *
 * Return: returns a*b
*/
int op_mul(int a, int b)
{
	return (a * b);
}

/* op_div - function that divides
 * @a: first
 * @b: second
 *
 * Return: returns a/b
*/
int op_div(int a, int b)
{
	return (a / b);
}

/* op_mod - function that returns the remainder of division
 * @a: first
 * @b: second
 *
 * Return: returns a%b
*/
int op_mod(int a, int b)
{
	return (a % b);
}
