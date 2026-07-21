#include "main.h"
#include <stdlib.h>
/**
 * _calloc - function that assigns memory to an array
 * of nmemb elements of size bytes, setting each byte to 0
 * @nmemb: first
 * @size: second
 *
 * Return: returns pointer, NULL if malloc fails or
 * either size or nmemb is 0
*/
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *p;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);
	p = malloc(nmemb * size);
	if (p == NULL)
		return (NULL);
	while (i < nmemb * size)
	{
		p[i] = 0;
		i++;
	}
	return (p);
}
