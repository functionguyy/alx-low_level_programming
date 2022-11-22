#include <stdlib.h>
/**
* free_grid - frees a 2-dimensional grid
* @grid: pointer to allocated memory for 2-D array
* @height: Number of rows in the 2-D array
*
*/

void free_grid(int **grid, int height)
{
	int i;

	i = 0;
	while (i < height)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
