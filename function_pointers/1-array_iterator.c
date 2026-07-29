#include <stdio.h>
#include "function_pointers.h"
/**
 * array_iterator - function that performs an action
 * of the passed function to an array of size size
 * @array: first
 * @size: second
 * @action: third
*/
void array_iterator(int *array, size_t size, void (*action)(int))
{
	int i = 0;
	int s = size;

	while (i < s)
	{
		action(array[i]);
		i++;
	}
}
