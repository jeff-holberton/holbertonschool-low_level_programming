#include "dog.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * init_dog - function that initialises a structure's data
 * @d: first
 * @name: second
 * @age: third
 * @owner: fourth
*/
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		return (NULL);
	d->name = name;
	d->age = age;
	d->owner = owner;
}
