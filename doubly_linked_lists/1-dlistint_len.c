#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * dlistint_len - function returns the size of
 * a doubly linked list
 * @h: first
 *
 * Return: returns the size of the list
 */
size_t dlistint_len(const dlistint_t *h)
{
	const dlistint_t *current;
	size_t n = 0;

	current = h;
	while (current)
	{
		n++;
		current = current->next;
	}
	return (n);
}
