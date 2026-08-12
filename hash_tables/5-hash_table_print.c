#include <stdio.h>
#include <stdlib.h>
#include "hash_tables.h"
#include <string.h>
/**
 * hash_table_print - fucntion that prints each element
 * of a hash table
 * @ht: first
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int index = 0;
	hash_node_t *current_node;
	int flag = 0;

	if (ht == NULL)
		return;
	printf("{");
	while (index < ht->size)
	{
		current_node = ht->array[index];
		while (current_node != NULL)
		{
			if (flag == 1)
				printf(", ");
			printf("'%s': '%s'", current_node->key, current_node->value);
			current_node = current_node->next;
			flag = 1;
		}
		index++;
	}
	printf("}\n");
}
