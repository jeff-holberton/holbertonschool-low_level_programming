#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * insert_dnodeint_at_index - function that adds a node at
 * a given index
 * @h: first
 * @idx: second
 * @n: third
 *
 * Return: returns the address of the new node, or NULL
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int i = 0;
	dlistint_t *new_node;
	dlistint_t *next_node;
	dlistint_t *prev_node;

	if (idx == 0)
		return (add_dnodeint(h, n));
	prev_node = *h;
	while (prev_node != NULL && i < idx - 1)
	{
		i++;
		prev_node = prev_node->next;
	}
	if (prev_node == NULL)
		return (NULL);
	if (prev_node->next == NULL)
		return (add_dnodeint_end(h, n));
	new_node = malloc(sizeof(*new_node));
	if (new_node == NULL)
		return (NULL);
	next_node = prev_node->next;

	new_node->n = n;
	new_node->next = next_node;
	new_node->prev = prev_node;

	prev_node->next = new_node;
	next_node->prev = new_node;
	return (new_node);
}
