#include <stdio.h>
/**
 * main - program that calculates numbers
 * inputted by user using scanf
 * Return: returns 0
*/
int main(void)
{
	int choice;
	int result;
	float a, b;
	float division;

	printf("Simple Calculator\n");
	printf("1) Add\n");
	printf("2) Subtract\n");
	printf("3) Multiply\n");
	printf("4) Divide\n");
	printf("0) Quit\n");

	while (1)
	{
		printf("Choice: ");
		if (scanf("%d", &choice) == 1)
		{
			if (choice == 0)
			{
				printf("Bye!\n");
				break;
			}
			printf("A: ");
			scanf("%f", &a);
			printf("B: ");
			scanf("%f", &b);
			if (choice == 1)
			{
				result = a + b;
				printf("Result: %d\n", result);
				break;
			}
			if (choice == 2)
			{
				result = a - b;
				printf("Result: %d\n", result);
				break;
			}
			if (choice == 3)
			{
				result = a * b;
				printf("Result: %d\n", result);
				break;
			}
			if (choice == 4)
			{
				if (b == 0)
				{
					printf("Error: division by zero\n");
					break;
				}
				division = a / b;
				printf("Result: %.1f\n", division);
				break;
			}
			printf("Invalid choice\n");
		}
		else
		{
			printf("Input Error\n");
			break;
		}
	}
	return (0);
}
