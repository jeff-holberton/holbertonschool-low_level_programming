#include <stdio.h>
#include <stdlib.h>
#include "hash_tables.h"
#include <string.h>
/**
 * hash_table_create - function that creates
 * a new hash table
 * @size: first
 *
 * Return: returns a pointer to the new table
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hash_table;
	hash_node_t **array;
	unsigned long int i = 0;

	hash_table = malloc(sizeof(*hash_table));
	if (hash_table == NULL)
		return (NULL);

	array = malloc(size * sizeof(hash_node_t *));
	if (array == NULL)
		return (NULL);
	while (i < size)
	{
		array[i] = NULL;
		i++;
	}

	hash_table->size = size;
	hash_table->array = array;
	return (hash_table);
}
