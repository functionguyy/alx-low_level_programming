#include "main.h"
/**
 * clear_bit - Sets the value of a bit at a given index to 0
 * @n: pointer to an integer
 * @index: the index, starting from 0 of the bit you want to set
 *
 * Return: returns 1 if it worked, or -1 if an occured
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (sizeof(n) * 8))
		return (-1);

	*n &= ~(1 << index);

	return (1);
}
