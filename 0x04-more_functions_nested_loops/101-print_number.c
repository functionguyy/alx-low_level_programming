#include "main.h"
/**
 * printMinus - checks if number is negative and prints a negative sign
 *@number: integer
 *
 * Return: a non-negative integer
 */
unsigned int printMinus(int number)
{
	unsigned int num;

	if (number < 0)
	{
		num = number * -1;
		_putchar('-');
	}
	else
		num = number;

	return (num);
}

/**
* print_number - Function that prints an integer.
* @n: int type number
* Description: Cna only use _putchar to print.
*/
void print_number(int n)
{
	unsigned int num, c, m;
	int sig;

	m = 1;
	c = 1;
	sig = 1;

	/* negatives */
	num = printMinus(n);

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
