#include "function_pointers.h"
#include <stdlib.h>
/**
 * array_iterator - a function that executes a function given as a parameter on
 * each element of an array
 * @array: array of integer
 * @size: size of the array
 * @action: pointer to the function to be executed
 *
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	/* declare variables */
	size_t loopIndex;

	/* initialize variable */
	loopIndex = 0;


	if (array == NULL || action == NULL)
		exit(EXIT_FAILURE);

	while (loopIndex < size)
	{
		action(array[loopIndex]);
		loopIndex++;
	}
}
