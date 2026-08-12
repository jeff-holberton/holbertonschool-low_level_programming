#include <stdio.h>
#include <stdlib.h>
#include "hash_tables.h"
#include <string.h>
/**
 * hash_table_delete - function that deletes a hash table
 * @ht: first
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *current_node;
	unsigned long int index = 0;

	if (ht == NULL)
		return;
	while (index < ht->size)
	{
		current_node = ht->array[index];
		while (current_node != NULL)
		{
			current_node = current_node->next;
			free(ht->array[index]->value);
			free(ht->array[index]->key);
			free(ht->array[index]);
			ht->array[index] = current_node;
		}
		index++;
	}
}
