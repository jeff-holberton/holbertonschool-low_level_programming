#include <stdio.h>
/**
 * main - function that prints 0-9
 * followed by a new line
 * Return: returns 0
*/
int main(void)
{
	int n;

	n = 0;
	while (n < 10)
	{
		printf("%d", n);
		n++;
	}
	putchar('\n');
	return (0);
}
