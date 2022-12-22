#include "main.h"
/**
* print_number - prints an integer to standard output
* @n: integer to be printed
*
* Return: nothing
*/
void print_number(int n)
{
	int num_pad;

	num_pad = 1000000000;
	if (n < 0)
	{
		_putchar('-');
		n = n * -1;
	}
	if (n != 0)
	{
		while (n / num_pad == 0)
		{
			num_pad = num_pad / 10;
		}
		while (num_pad >= 1)
		{
			_putchar((n / num_pad) + '0');
			n = n % num_pad;
			num_pad = num_pad / 10;
		}

	}
	else
		_putchar('0');

}
