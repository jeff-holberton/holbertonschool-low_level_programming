#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lists.h"
/**
 * print_list - function that prints each element
 * of a linked list
 * @h: first
 *
 * Return: elements in the list
 */
size_t print_list(const list_t *h)
{
	size_t i = 0;
	const list_t *temp;

	temp = h;
	if (h == NULL)
		return (0);
	while (temp != NULL)
	{
		if (temp->str == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
		{
			printf("[%d] %s\n", temp->len, temp->str);
		}
		temp = temp->next;
		i++;
	}
	return (i);
}
