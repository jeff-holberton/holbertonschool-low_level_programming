#include "main.h"
/**
 * _atoi - function that converts a string to an integer
 * @s: first operand
 *
 * Return: returns num, 0 if no number is found
*/
int _atoi(char *s)
{
	int num = 0;
	int i = 0;
	int sign = 1;
	int start;
	int end;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign = sign * -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			start = i;
			while (s[i] >= '0' && s[i] <= '9')
			{
				i++;
			}
			end = i - 1;
			while (start <= end)
			{
				if (sign == 1)
					num = num * 10 + (s[start] - '0');
				else
					num = num * 10 - (s[start] - '0');
				start++;
			}
			return (num);
		}
		i++;
	}
	return (0);
}
