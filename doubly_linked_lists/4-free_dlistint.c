#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * free_dlistint - function that frees all elements
 * within a doubly linked list
 * @head: first
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *current;

	current = head;
	while (current != NULL)
	{
		current = current->next;
		free(head);
		head = current;
	}
}
