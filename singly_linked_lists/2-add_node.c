#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lists.h"
/**
 * add_node - function that creates a new node at the
 * start of a linked list
 * @head: first
 * @str: second
 *
 * Return: returns the address of a the new element,
 * or NUll if failed
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *temp;
	int len = 0;

	temp = malloc(sizeof(list_t));
	if (temp == NULL)
	{
		return (NULL);
	}
	while (str[len] != '\0')
		len++;
	temp->len = len;
	temp->str = strdup(str);
	if (temp->str == NULL)
	{
		free(temp);
		return (NULL);
	}
	temp->next = *head;
	*head = temp;
	return (temp);
}
