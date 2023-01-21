#include <stddef.h>
/**
* array_iterator - A function that executes a function given as a parameter on
* each element of an array
* @array: pointer to an int type
* @size: is the size of the array
* @action: pointer to a function that accepts and int type and returns void
*
*
**/

void array_iterator(int *array, size_t size, void (*action)(int num))
{
	unsigned int i;
	int num;


	if (array && action && size > 0)
	{
		for (i = 0; i < size; i++)
		{
			num = array[i];
			(*action)(num);
		}

	}
}
