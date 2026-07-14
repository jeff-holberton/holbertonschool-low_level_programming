#include "main.h"
/**
 * reverse_array - function that reverses an array of int
 * @a: first
 * @n: second
*/
void reverse_array(int *a, int n)
{
	int i = 0;
	int c = n - 1;
	int temp;

	while (i < c)
	{
		temp =  a[i];
		a[i] = a[c];
		a[c] = temp;
		i++;
		c--;
	}
}
