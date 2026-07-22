#include "dog.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * new_dog - function that creates a new dog
 * @name: first
 * @age: second
 * @owner: third
 *
 * Return: returns pointer to the new dog
*/
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;
	char *n;
	char *o;
	int i = 0;

	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
	{
		free(dog);
		return (NULL);
	}
	n = malloc(sizeof(name));
	if (n == NULL)
		return (NULL);
	o = malloc(sizeof(owner));
	if (o == NULL)
		return (NULL);
	while (name[i] != '\0')
	{
		n[i] = name[i];
		i++;
	}
	n[i] = '\0';
	i = 0;
	while (owner[i] != '\0')
	{
		o[i] = owner[i];
		i++;
	}
	o[i] = '\0';
	dog->name = n;
	dog->age = age;
	dog->owner = o;
	return (dog);
}
