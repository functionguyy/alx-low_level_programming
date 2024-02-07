#include <stdlib.h>
#include <stdio.h>
#include "search_algos.h"
/**
 * linear_search - searches for a value in an array of integers using Linear
 * search algorithm
 * @array: pointer to the first element of an array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: function must return first index where value is located, if
 * value is not present in array or if array is Null return -1
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
