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
	size_t l, r, m, i;

	l = 0;
	r = size - 1;

	while (l <= r)
	{
		m = l + (r - l) / 2;

		printf("Searching in array: ");
		for (i = l; i <= r;)
		{
			printf("%d", array[i]);

			if (i != r)
				printf(", ");
			i++;
		}
		printf("\n");


		if (array[m] < value)
			l = m + 1;
		else if (array[m] > value)
			r = m - 1;
		else
			return (m);
	}

	return (-1)


}
