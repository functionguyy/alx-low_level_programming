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

	while (idx < size)
	{
		if (array[idx] == value)
			return (idx);
		idx++;
	}

}
