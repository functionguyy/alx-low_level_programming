#include "main.h"
/**
 * print_binary - prints the binary representation of a number
 * @n: number to printed in binary representation
 *
 * Return: returns nothing
 */
void print_binary(unsigned long int n)
{
	/* declare variables */
	unsigned long int mask, num, count;

	/* initialize variables */
	count = 0;
	mask = 1 << n;
	num = n | (mask & n);

	if (n == 0)
		_putchar(0 + '0');
	/* count the number bits in n */
	while (num != 0)
	{
		num >>= 1;
		count++;
	}

	/* print the value of each bit in n */
	while (count > 0)
	{
		if (n & (1 << (count - 1)))
			_putchar(1 + '0');
		else
			_putchar(0 + '0');

		num >>= 1;

		count--;
	}
}
