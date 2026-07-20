#include "main.h"
#include <stdlib.h>
/**
 * str_concat - function that allocates memory
 * to an array and copies two strings in it
 * @s1: first
 * @s2: second
 *
 * Return: returns NULL on failure, otherwise
 * a pointer to the created array
*/
char *str_concat(char *s1, char *s2)
{
	int size1 = 0;
	int size2 = 0;
	char *concat;
	int i = 0;
	int j = 0;

	if (s1 != NULL)
	{
		while (s1[size1] != '\0')
		{
			size1++;
		}
	}
	if (s2 != NULL)
	{
		while (s2[size2] != '\0')
		{
			size2++;
		}
	}
	concat = malloc(((size1 + size2) * sizeof(char)) + 1);
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
