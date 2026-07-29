#include <stdio.h>
#include "function_pointers.h"
/**
 * print_name - function that calls passed function with argument name
 * @name: first
 * @f: second
*/
void print_name(char *name, void (*f)(char *))
{
	f(name);
}
