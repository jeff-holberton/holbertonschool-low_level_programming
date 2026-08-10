#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * print_dlistint - function that prints each element
 * of a doubly linked list
 * @h: first
 *
 * Return: returns the size of the list
 */
size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *current;
	size_t n = 0;

	current = h;
	while (current)
	{
		printf("%d\n", current->n);
		n++;
		current = current->next;
	}
	return (n);
}
