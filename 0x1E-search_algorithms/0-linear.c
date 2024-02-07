#include <stdlib.h>
#include <stdio.h>
#include "search_algos.h"
/**
 *
 *
 *
 *
 *
 *
 */
int linear_search(int *array, size_t size, int value)
{
	size_t idx;

	idx = 0;

	if (array == NULL)
		return (-1);

	while (idx < size)
	{
		printf("Value checked array[%lu] = [%d]\n", idx, array[idx]);
		if (array[idx] == value)
			return (idx);
		idx++;
	}

	return (-1);
}
