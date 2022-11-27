#include <stdlib.h>
/**
* array_range - creates an array of integers
* @min: mininum number
* @max: maximum number
*
* Description: The array created should contain all the values from
* min(included) to max(included), ordered from min to max
* Return: pointer to the newly created array or NULL if min > max or if malloc
* fails.
*/

int *array_range(int min, int max)
{
	int val_count, *arr_ptr, idx;
	int seen_min;

	if (min > max)
		return (NULL);

	val_count = 1;
	seen_min = min;
	while (seen_min <= max)
	{
		seen_min += 1;
		val_count++;
	}
	arr_ptr = malloc(sizeof(*arr_ptr) * val_count);

	if (!arr_ptr)
		return (NULL);
	idx = 0;
	while (idx < val_count)
	{
		arr_ptr[idx] = min;
		min += 1;
		idx++;
	}

	return (arr_ptr);
}
