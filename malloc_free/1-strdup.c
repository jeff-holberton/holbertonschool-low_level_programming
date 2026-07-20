#include "main.h"
#include <stdlib.h>
/**
 * _strdup - function that allocates memory
 * to an array and copies a given string into it
 * @str: first
 *
 * Return: returns NULL if str is NULL, otherwise
 * a pointer to the created array
*/
char *_strdup(char *str)
{
	int size = 0;
	int i = 0;
	char *copy;

	if (str == NULL)
		return (NULL);
	while (str[size] != '\0')
	{
		size++;
	}
	size++;
	copy = malloc(size * sizeof(char));
	if (copy == NULL)
		return (NULL);
	while (i < size)
	{
		copy[i] = str[i];
		i++;
	}
	return (copy);
}
