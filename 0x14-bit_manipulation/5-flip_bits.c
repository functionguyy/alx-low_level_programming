#include "main.h"
/**
 * flip_bits - returns the number of bits you would need to flip to get from
 * one number to another
 * @n: integer
 * @m: integer
 *
 * Return: count of bits needed to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	/* declare variables */
	unsigned int cnt;
	unsigned long int flp;

	/* initialize variables */
	cnt = 0;
	flp = n ^ m;

	while (flp)
	{
		cnt += flp & 1;
		flp >>= 1;
	}

	return (cnt);
}
