#include "main.h"

/**
* print_number - Function that prints an integer.
* @n: int type number
* Description: Cna only use _putchar to print.
*/
void print_number(int n)
{
	unsigned int num, c, sig, m; /* convert int to long */

	m = 1;
	c = 1;
	sig = 1;
	num = 0;

	/* negatives */
	if (n < 0)
	{
		num = n * -1;
		_putchar('-');
	}
	else
		num = n;

	/* count up */
	while (c)
	{
		if (num / (m * 10) > 0)
		{
			m *= 10;
		} else
		{
			c = 0;
		}
	}

	/* count down */
	while (sig > 0)
	{
		if (m == 1)
		{
			_putchar(num % 10 + '0');
			sig = -1;
		}
		else
		{
			_putchar((num / m % 10) + '0');
			m /= 10;
		}
	}
}
