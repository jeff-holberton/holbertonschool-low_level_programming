#include <stdlib.h>
#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * print_all - function that prints anything
 * @format: first
 * @...: third
*/
void print_all(const char * const format, ...)
{
	va_list args;
	int i = 0;
	char *temp;
	int flag = 0;

	if (format != NULL)
	{
		va_start(args, format);
		while (format[i] != '\0')
		{
			switch (format[i])
			{
				case 'c':
					printf("%c", (char)va_arg(args, int));
					flag = 1;
					break;
				case 'i':
					printf("%d", va_arg(args, int));
					flag = 1;
					break;
				case 'f':
					printf("%f", (float)va_arg(args, double));
					flag = 1;
					break;
				case 's':
					temp = va_arg(args, char *);
					if (temp == NULL)
					{
						printf("(nil)");
						flag = 1;
						break;
					}
					printf("%s", temp);
					flag = 1;
					break;
			}
			i++;
			while (flag == 1 && format[i] != '\0')
			{
				printf(", ");
				flag = 0;
			}
		}
		va_end(args);
	}
	printf("\n");
}
