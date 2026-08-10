#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * delete_dnodeint_at_index - function that removes a node at
 * a given index
 * @head: first
 * @index: second
 *
 * Return: returns 1 if succeeded, -1 if failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current, *prev, *next;
	unsigned int i = 0;

	current = *head;
	if (*head == NULL)
		return (-1);
	while (i < index && current != NULL)
	{
		i++;
		current = current->next;
	}
	if (current == NULL)
		return (-1);
	prev = current->prev;
	next = current->next;

	if (prev != NULL)
		prev->next = next;
	else
		*head = next;
	if (next != NULL)
		next->prev = prev;

	free(current);
	return (1);
}
