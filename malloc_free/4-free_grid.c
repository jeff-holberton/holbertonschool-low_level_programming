#include "main.h"
#include <stdlib.h>
/**
 * free_grid - function that frees
 * the previously allocated memory of the
 * allocate_grid program
 * @grid: first
 * @height: second
*/
void free_grid(int **grid, int height)
{
	int i = 0;

	while (i < height)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
