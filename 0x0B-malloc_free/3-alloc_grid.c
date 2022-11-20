#include <stdlib.h>
/**
 * alloc_grid - Returns a pointer to a 2 dimensional array of integer
 * integers with each element initialized to 0.
 * @width: The width of the 2-D array.
 * @height: The height of the 2-D array.
 *
 * Return: Pointer to 2- array or NULL if width <= 0, height <=0,
 * or the memory allocation fails.
 *
 */

int **alloc_grid(int width, int height)
{
	int i, j, **p;

	if (width <= 0 || height <= 0)
		return (NULL);

	p = malloc(sizeof(int *) * height);

	if (p == NULL)
		return (NULL);

	i = 0;
	while (i < height)
	{
		p[i] = malloc(sizeof(int) * width);

		if (p[i] == NULL)
		{
			while (i >= 0)
			{
				free(p[i]);
				i--;
			}
			free(p);
			return (NULL);
		}
		i++;
	}

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			p[i][j] = 0;
			j++;
		}
		i++;
	}
	return (p);
}
