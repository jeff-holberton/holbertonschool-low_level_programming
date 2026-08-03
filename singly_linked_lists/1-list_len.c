#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lists.h"
/**
 * list_len - function that returns the length
 * of a linked list
 * @h: first
 *
 * Return: length of a list
 */
size_t list_len(const list_t *h)
{
	size_t len = 0;
	const list_t *temp = h;

	while (temp != NULL)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}
