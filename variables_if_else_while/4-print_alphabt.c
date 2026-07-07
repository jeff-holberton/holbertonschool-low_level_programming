#include <stdio.h>
/**
 * main - function that prints the alphabet lower case
 * followed by a new line, except q and e
 * Return: returns 0
*/
int main(void)
{
	int n;

	for (n = 97 ; n < 123 ; n++)
	{
		if (n != 101 && n != 113)
		putchar(n);
	}
	putchar('\n');
	return (0);
}

