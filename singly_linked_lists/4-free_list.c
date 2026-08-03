#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lists.h"
/**
 * free_list - function that frees each node of a list
 * @head: first
 */
void free_list(list_t *head)
{
	list_t *delete;

	delete = head;
	while (delete != NULL)
	{
		head = head->next;
		free(delete->str);
		free(delete);
		delete = head;
	}
}
