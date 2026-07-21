#include "main.h"
#include <stdlib.h>
/**
 * string_nconcat - function that concatenates two
 * strings, s1 and n bytes of s2, allocating memory
 * dynamically
 * @s1: first
 * @s2: second
 * @n: third
 *
 * Return: returns pointer, NULL if malloc fails
*/
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	int size1, size2;
	int i = 0;
	int  j = 0;
	char *concat;

	if (s1 != NULL)
	{
		while (s1[size1] != '\0')
			size1++;
	}
	else
		size1 = 0;
	if (s2 != NULL)
	{
		while (s2[size2] != '\0')
			size2++;
	}
	else
		size2 = 0;
	if (n < size2)
		size2 = n;
	concat = malloc(size1 + size2 + 1);
	if (concat == NULL)
		return (NULL);
	while (i < size1)
	{
		concat[i] = s1[i];
		i++;
	}
	while (j < size2)
	{
		concat[i] = s2[j];
		i++;
		j++;
	}
	concat[i] = '\0';
	return (concat);
}
