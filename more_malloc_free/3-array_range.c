#include "main.h"
#include <stdlib.h>
/**
 * array_range - function that crates an array of integers
 * filling each element with the values between min and max included
 * ordered from min to max
 * @min: first
 * @max: second
 *
 * Return: returns pointer, NULL if malloc fails
 * or if min > max
*/
int *array_range(int min, int max)
{
	int i = 0;
	int counter = min;
	int *array;

	if (min > max)
		return (NULL);
	array = malloc((max - min + 1) * sizeof(int));
	if (array == NULL)
		return (NULL);
	while (counter <= max)
	{
		array[i] = counter;
		counter++;
		i++;
	}
	return (array);
}
