/**
* int_index - A function that searches for an integer
* @array: pointer to int type
* @size: number of elements in the array
* @cmp: pointer to function that accepts int type and return int type
*
* Return: index of the first element which cmp function does not return 0 or
*-1 if no element matches or size is less than or equal to zero
*/
int int_index(int *array, int size, int (*cmp)(int n))
{
	int i, num;


	if (size <= 0)
	{
		return (-1);
	}
	if (array && cmp)
	{
		for (i = 0; i < size; i++)
		{
			num = (*cmp)(array[i]);
			if (num > 0)
			{
				return (i);
			}
		}
	}
	return (-1);
}
