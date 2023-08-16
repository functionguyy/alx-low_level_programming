#include "function_pointers.h"
#include <stdlib.h>
/**
 * int_index - function that searches for an integer
 * @array: array
 * @size: number of elements in the array
 * @cmp: pointer to the function to be used to compare values
 *
 * Return: return the index of the first element for which the cmp function
 * does not return 0. if not element matches, return -1
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	/* declare variables */
	int loopIndex, matchIndex;

	/* initialize variables */
	loopIndex = 0;
	matchIndex = -1;

	/* confirm pointer arguments are not NULL */
	if (array == NULL || cmp == NULL)
		exit(EXIT_FAILURE);

	/* confirm size is not zero or negative */
	if (size <= 0)
		return (matchIndex);

	while (loopIndex < size)
	{
		if (cmp(array[loopIndex]) != 0)
		{
			matchIndex = loopIndex;
			return (matchIndex);
		}
		loopIndex++;
	}

	return (matchIndex);
}
