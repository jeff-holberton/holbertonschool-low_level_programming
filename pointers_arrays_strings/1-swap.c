#include "main.h"
/**
 * swap_int - function that swaps two variables
 * @a: first operand
 * @b: second operand
*/
void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
