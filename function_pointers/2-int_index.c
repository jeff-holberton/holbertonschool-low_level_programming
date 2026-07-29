#include <stdio.h>
#include "function_pointers.h"
/**
 * int_index - function that searches for an integer
 * using passed function cmp through array of size size
 * @array: first
 * @size: second
 * @cmp: third
 *
 * Return: returns index of first valid value, or -1
*/
int int_index(int *array, int size, int (*cmp)(int))
{
	int i = 0;

	if (size <= 0)
		return (-1);
	while (i < size)
	{
		if (cmp(array[i]) != 0)
			return (i);
		i++;
	}
	return (-1);
}
