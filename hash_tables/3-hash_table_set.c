#include <stdio.h>
#include <stdlib.h>
#include "hash_tables.h"
#include <string.h>
/**
 * hash_table_set - function that adds an element to the hash
 * table
 * @ht: first
 * @key: second
 * @value: third
 *
 * Return: returns a 1 if succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	char *new_value;
	unsigned long int index;
	hash_node_t *new_node;
	hash_node_t *current;
	char *new_key;

	if (ht == NULL || key == NULL || strlen(key) == 0)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	new_value = strdup(value);
	if (new_value == NULL)
		return (0);

	current = ht->array[index];
	while (current != NULL)
	{
		if (strcmp(key, current->key) == 0)
		{
			free(current->value);
			current->value = new_value;
			return (1);
		}
		current = current->next;
	}

	new_key = strdup(key);
	if (new_key == NULL)
		return (0);
	new_node = malloc(sizeof(*new_node));
	if (new_node == NULL)
		return (0);

	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	new_node->value = new_value;
	new_node->key = new_key;
	return (1);
}
