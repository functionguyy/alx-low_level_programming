#include "main.h"
#include <stdlib.h>
/**
 * initializer - function that initializes a 2D array of integer with 0
 * @matrix: 2D array of integers
 * @height: number of rows in the 2D array
 * @width: number of columns in the 2D array
 *
 *
 */
void initializer(int **matrix, int height, int width)
{
	/* Declare variables */
	int row, column;

	/* initialize variables */
	row = 0;
	column = 0;

	/* initialize the 2D array */
	for (row = 0; row < height; row++)
	{
		for (column = 0; column < width; column++)
		{
			matrix[row][column] = 0;
		}
	}

}

/**
 * freeMultiDimArr - function frees malloc memory allocation for row in a 2D
 * array of integers
 * @matrix: 2D array of integer
 * @index: number of rows allocated
 *
 */
void freeMultiDimArr(int **matrix, int index)
{
	if (index > 0)
	{
		while (index >= 0)
		{
			free(matrix[index]);
			index--;
		}
	}
	else
		free(matrix[index]);

	free(matrix);
}


/**
 * alloc_grid - function that returns a pointer to a 2D array of integers
 * @width: number of columns in the 2D array
 * @height: number of rows in the 2D array
 *
 * Description: each element of the grid is initialized to 0
 * Return: pointer to a 2D array or NULL otherwise
 */

int **alloc_grid(int width, int height)
{
	/* Declare variables */
	int **multiDimArr, loopIndex;


	/* Initialize variables */
	multiDimArr = NULL;
	loopIndex = 0;


	/* Confirm that both parameters passed are not less than or equal to zero */
	if (width <= 0 || height <= 0)
		return (NULL);


	/* use height parameter to request 2D array rows memory allocation */
	multiDimArr = malloc(sizeof(int *) * height);

	/* confirm memory allocation */
	if (multiDimArr == NULL)
		return (NULL);

	/* use width parameter to request 2D array columns memory allocation */
	while (loopIndex < height)
	{
		multiDimArr[loopIndex] = malloc(sizeof(int) * width);
		/* confirm memory allocation */
		if (multiDimArr[loopIndex] == NULL)
		{
			freeMultiDimArr(multiDimArr, loopIndex);
			return (NULL);
		}

		loopIndex++;
	}

	/* initialize the 2D array */
	initializer(multiDimArr, height, width);

	/* return pointer to a 2D array of integers */
	return (multiDimArr);
}
