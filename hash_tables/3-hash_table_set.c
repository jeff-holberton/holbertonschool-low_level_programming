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
	hash_node_t *current_node;

	new_value = strdup(value);
	if (new_value == NULL)
		return (0);
	if (key == NULL || strlen(key) == 0)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	current_node = ht->array[index];

	new_node = malloc(sizeof(*new_node));
	if (new_node == NULL)
		return (0);

	new_node->next = NULL;
	new_node->value = new_value;
	new_node->key = (char *)key;

	if (current_node == NULL)
	{
		ht->array[index] = new_node;
		return (1);
	}
	while (current_node->next != NULL)
		current_node = current_node->next;
	current_node->next = new_node;
	return (1);
}
