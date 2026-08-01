#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * main - program that prints all its arguments
 * @argc: first
 * @argv: second
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int i = 0;

	while (i < argc)
	{
		printf("%s\n", argv[i]);
		i++;
	}
	return (0);
}
