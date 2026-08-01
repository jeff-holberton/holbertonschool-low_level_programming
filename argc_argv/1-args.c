#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * main - function that prints number of arguments
 * passed
 * @argc: first
 * @argv: second
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	(void)argv;
	printf("%d\n", argc - 1);
	return (0);
}
