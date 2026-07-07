#include <stdio.h>
/**
 * main - function that prints all numbers in base 16 lowercase
 * followed by a new line
 * Return: returns 0
*/
int main(void)
{
	int n;
	int l;

	for (n = 48 ; n < 58 ; n++)
		putchar(n);
	for (l = 97 ; l < 103 ; l++)
		putchar(l);
	putchar('\n');
	return (0);
}
