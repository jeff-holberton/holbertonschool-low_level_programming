#include <stdio.h>
#include <stdlib.h>
/**
 * main - program that prints the result of the
 * sum of all arguments passed to the program
 * printing error instead, if any arguments contain
 * any character other than a number
 * @argc: first
 * @argv: second
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int i = 1;
	int j = 0;
	int sum = 0;

	while (i < argc)
	{
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf("Error\n");
				return (1);
			}
			j++;
		}
		sum += atoi(argv[i]);
		i++;
	}
	printf("%d\n", sum);
	return (0);
}
