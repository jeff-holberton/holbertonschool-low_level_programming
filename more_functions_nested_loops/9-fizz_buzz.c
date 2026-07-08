#include "main.h"
#include <stdio.h>
/**
 * main - program that prints the FIzz-Buzz test
 *
 * Return: returns 0
*/
int main(void)
{
	int i;

	for (i = 1 ; i < 101 ; i++)
	{
		if (((i % 3) == 0) && ((i % 5) == 0))
		{
			printf("FizzBuzz ");
		}
		else if ((i % 3) == 0)
		{
			printf("Fizz ");
		}
		else if ((i % 5) == 0 && i == 100)
		{
			printf("Buzz\n");
		}
		else if ((i % 5) == 0)
		{
			printf("Buzz ");
		}
		else
		{
			printf("%d ", i);
		}
	}
	return (0);
}
