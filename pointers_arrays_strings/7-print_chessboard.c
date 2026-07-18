#include "main.h"
#include <stdio.h>
/**
 * print_chessboard - function that prints each element
 * of an array of arrays
 * @a: first operand
*/
void print_chessboard(char (*a)[8])
{
	int i, j;

	i = 0;
	j = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			printf("%c", a[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
