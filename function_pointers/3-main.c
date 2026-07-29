#include <stdio.h>
#include <string.h>
#include "3-calc.h"
#include <stdlib.h>
/**
 * main - main function
 * @argc: number of arguments
 * @argv: strings of arguments
 *
 * Return: returns 0 if successful, 99-98-100 if not
*/
int main(int argc, char *argv[])
{
	char *operators = "+-*/%";
	int a, b, result;
	int (*func)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		return (98);
	}

	a = atoi(argv[1]);
	b = atoi(argv[3]);
	if (strchr(operators, argv[2][0]) == NULL || strlen(argv[2]) != 1)
	{
		printf("Error\n");
		return (99);
	}
	if ((argv[2][0] == '/' || argv[2][0] == '%') && b == 0)
	{
		printf("Error\n");
		return (100);
	}
	func = get_op_func(argv[2]);
	result = func(a, b);
	printf("%d\n", result);
	return (0);
}
