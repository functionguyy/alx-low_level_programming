#include "main.h"
#include <stdlib.h>
/**
 * free_grid - function frees malloc memory allocation of a 2D array of
 * integers
 * @grid: 2D array of integers
 * @height: number of rows allocated
 *
 */
void free_grid(int **grid, int height)
{
	if (grid == NULL)
		return;
	if (height > 0)
	{
		while (height >= 0)
		{
			free(grid[height]);
			height--;
		}
	}
	else
		free(grid[height]);

	free(grid);
}
