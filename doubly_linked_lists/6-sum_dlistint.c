#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * sum_dlistint - function that sums all the data of a
 * doubly linked list
 * @head: first
 *
 * Return: returns the sum
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;
	dlistint_t *current;

	if (head == NULL)
		return (sum);
	current = head;
	while (current)
	{
		sum = sum + current->n;
		current = current->next;
	}
	return (sum);
}
