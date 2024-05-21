#include <stdlib.h>
#include <stdio.h>
#include "search_algos.h"
/**
 * binary_search - searches for value in a sorted array of integers using
 * binary search algorithm
 * @array: pointer to the first element of an array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: function returns the index where value is located, if value is not
 * present in array or if array is NULL, function returns -1
 */
int binary_search(int *array, size_t size, int value)
{
	size_t l, r, m, i;

	l = 0;
	r = size - 1;

	if (array == NULL || size == 0)
		return (-1);
	while (l <= r)
	{
		m = l + (r - 1) / 2;

		printf("Searching in array: ");
		for (i = l; l <= r;)
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

	return (-1);
}
