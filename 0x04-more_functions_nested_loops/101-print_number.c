#include "main.h"
/**
 * exponent - calculate the exponent of a base 10 number
 * @digit: a positive base 10 number
 *
 * Return: returns the exponent of the number passed to it.
 *
 */
unsigned int exponent(unsigned int digit)
{
	/* declare variables */
	unsigned int exp, count;

	count = 0;
	exp = 1;

	/* get the numbers of tens in the number */
	while (digit > 0)
	{
		digit = digit / 10;
		count++;
	}

	/* calculate its exponent */
	while (count > 1)
	{
		exp = exp * 10;
		count--;
	}

	return (exp);
}
/**
* print_number - Function that prints an integer.
* @n: int type number
* Description: Cna only use _putchar to print.
*/
void print_number(int n)
{
	/* declare variables */
	unsigned int num, exp, number;

	/* account for negative number */
	if (n < 0)
	{
		num = n * -1;
		_putchar('-');
	}
	else
		num = n;

	/* calculate the exponent */
	exp = exponent(num);

	/* print an integer */
	while (exp > 0)
	{
		number = num / exp;
		_putchar(number + '0');
		num = num - (number * exp);
		exp /= 10;
	}
}
