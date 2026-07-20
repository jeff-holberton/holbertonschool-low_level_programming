#include "main.h"
#include <stdlib.h>
/**
 * create_array - function that allocates memory
 * to an array and initialises it with char c
 * @size: first
 * @c: second
 *
 * Return: returns NULL if size is 0, otherwise
 * a pointer to the created array
*/
char *create_array(unsigned int size, char c)
{
	char *p;
	unsigned int i = 0;

	if (size == 0)
	{
		return (NULL);
	}
	p = malloc(size * sizeof(char));
	if (p == NULL)
		return (NULL);
	while (i < size)
	{
		p[i] = c;
		i++;
	}
	return (p);
}
