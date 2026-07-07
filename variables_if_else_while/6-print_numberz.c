#include <stdio.h>
/**
 * main - function that prints 0-9 only using putchar
 * followed by a new line
 * Return: returns 0
*/
int main(void)
{
	int n;

	for (n = 48 ; n < 58 ; n++)
	{
		putchar(n);
	}
	putchar('\n');
	return (0);
}
