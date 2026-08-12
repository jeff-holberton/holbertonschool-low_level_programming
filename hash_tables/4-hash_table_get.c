#include <stdio.h>
#include <stdlib.h>
#include "hash_tables.h"
#include <string.h>
/**
 * hash_table_get - fucntion that returns the value of a node
 * within a hash table, given a specific key
 * @ht: first
 * @key: second
 *
 * Return: returns a value, NULL if failed
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *current;
	unsigned long int index;

	if (ht == NULL || key == NULL)
		return (NULL);
	index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[index];
	while (current != NULL && strcmp(key, current->key) != 0)
		current = current->next;
	if (current == NULL)
		return (NULL);
	return (current->value);
}
