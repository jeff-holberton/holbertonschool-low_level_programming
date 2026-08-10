#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * get_dnodeint_at_index- function that returns the address
 * of the node of the nth index
 * @head: first
 * @index: second
 *
 * Return: returns the nth node
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i = 0;
	dlistint_t *current;

	if (head == NULL)
		return (NULL);
	current = head;
	while (i < index && current->next != NULL)
	{
		i++;
		current = current->next;
	}
	if (i < index)
		return (NULL);
	return (current);
}
