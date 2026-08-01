#include <stdio.h>
#include <stdlib.h>
/**
 * main - program that prints the result of the
 * multiplication of two arguments passed to the program
 * @argc: first
 * @argv: second
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int mul;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	mul = atoi(argv[1]) * atoi(argv[2]);
	printf("%d\n", mul);
	return (0);
}
