#include <stdio.h>
#include <stdlib.h>
#include "hash_tables.h"
#include <string.h>
/**
 * key_index - function that returns a key index given
 * a key
 * @key: first
 * @size: second
 *
 * Return: returns a key index
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int key_index;

	key_index = hash_djb2(key) % size;
	return (key_index);
}
