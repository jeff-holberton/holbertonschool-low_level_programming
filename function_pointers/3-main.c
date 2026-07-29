#include <stdio.h>
#include <string.h>
#include "3-calc.h"
#include <stdlib.h>
/**
 *
 *
 *
 *
*/
int main(int argc, char *argv[])
{
	char *operators = "+-*/%";
	int a, b , result;
	char op;
	op_t operation;

	if (argc != 4)
	{
		printf("Error\n");
		return (98);
	}

	a = atoi(argv[1]);
	b = atoi(argv[3]);
	op = argv[2][0];

	if (strchr(operators, op) == NULL)
	{
		printf("Error\n");
		return (99);
	}
	if ((op == '/' || op == '%') && b == 0)
	{
		printf("Error\n");
		return (100);
	}
	operation.f = get_op_func(&op);
	result = operation.f(a, b);
	printf("%d\n", result);
	return (0);
}
