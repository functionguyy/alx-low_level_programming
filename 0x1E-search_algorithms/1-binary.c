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
 *
 */
int binary_search(int *array, size_t size, int value)
{
	size_t l, r, m;

	l = 0;
	r = size - 1;

	while (l <= r)
	{
		m = (l + r) / 2;

		if (array[m] < value)
			l = m + 1;
		else if (array[m] > value)
			r = m - 1;
		else
			return m;

	}
}
