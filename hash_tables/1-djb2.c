#include <stdio.h>
#include <stdlib.h>
#include "hash_tables.h"
#include <string.h>
/**
 * hash_djb2 - function that returns hash code for
 * a given string using djb2 algorithm
 * @str: first
 *
 * Return: returns a hash value
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int c;

	hash = 5381;
	while ((c = *str++))
	{
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}
	return (hash);
}
