#include "main.h"
/**
 * _strspn - function that counts characters containted
 * in string s that match a character in string
 * accept, until a character doesn't match
 * @s: first
 * @accept: second
 *
 * Return: returns counter
*/
int _strspn(char *s, char *accept)
{
	int i = 0;
	int n = 0;
	int counter = 0;

	while (s[i] != '\0')
	{
		n = 0;
		while (accept[n] != '\0')
		{
			if (s[i] == accept[n])
			{
				counter++;
				break;
			}
			else
			n++;
		}
		if (accept[n] == '\0')
			break;
		i++;
	}
	return (counter);
}
