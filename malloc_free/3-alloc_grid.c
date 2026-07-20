#include "main.h"
#include <stdlib.h>
/**
 * alloc_grid - function that allocates memory
 * to a two dimentional array and sets each cell to 0
 * @width: first
 * @height: second
 *
 * Return: returns NULL on failure, otherwise
 * a pointer to the first pointer
*/
int **alloc_grid(int width, int height)
{
	int i = 0;
	int **grid;
	int j = 0;

	if (width <= 0 || height <= 0)
		return (NULL);
	grid = malloc(height * sizeof(int *));
	if (grid == NULL)
		return (NULL);
	while (i < height)
	{
		grid[i] = malloc(width * sizeof(int));
		if (grid[i] == NULL)
		{
			while (i > 0)
			{
				free(grid[i]);
				i--;
			}
			free(grid);
			return (NULL);
		}
		j = 0;
		while (j < width)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
	return (grid);
}
