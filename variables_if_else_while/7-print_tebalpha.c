#include <stdio.h>
/**
 * main - function that prints the alphabet lower case
 * in reverse, followed by a new line
 * Return: returns 0
*/
int main(void)
{
	int n;

	for (n = 122 ; n > 96 ; n--)
	{
		putchar(n);
	}
	putchar('\n');
	return (0);
}

