#include "main.h"
/**
 * _strcpy - function that copies a string from source to destination
 * @dest: first operand
 * @src: second operand
 *
 * Return: returns a pointer to the copied string;
*/
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (&(*dest));
}
