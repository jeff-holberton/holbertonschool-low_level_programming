#include <stdio.h>
/**
 * main - function that prints 0-9 followed by a , and a space
 * followed by a new line
 * Return: returns 0
*/
int main(void)
{
	int n;

	for (n = 48 ; n < 58 ; n++)
	{
		putchar(n);
		if (n != 57)
		{
			putchar(44);
			putchar(32);
		}
	}
	putchar('\n');
	return (0);
}
