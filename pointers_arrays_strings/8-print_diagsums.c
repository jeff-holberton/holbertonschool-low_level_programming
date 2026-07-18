#include "main.h"
#include <stdio.h>
/**
 * print_diagsums - function that prints the sums of the
 * two diagonals of a matrix of integers
 * @a: first
 * @size: second
*/
void print_diagsums(int *a, int size)
{
	int i, j;
	int sum1 = 0;
	int sum2 = 0;

	i = 0;
	j = size - 1;
	while (i < size)
	{
		sum1 = sum1 + *(a + (size * i) + i);
		sum2 = sum2 + *(a + (size * i) + j);
		j--;
		i++;
	}
	printf("%d, %d\n", sum1, sum2);
}
