#include "main.h"
/**
* print_number - prints an integer to standard output
* @n: integer to be printed
*
* Description: You can only use _putchar function to print
* you are not allowed to use long
* you are not allowed to use arrays or pointers
* you are not allowed to hard-code special values
* Return: Nothing
*/
void print_number(int n)
{
	unsigned int num = n;
	unsigned int num_pad = 1000000000;

	if (n < 0)
	{
		_putchar('-');
		num = num * -1;
	}

	if (n != 0)
	{
		while (num / num_pad == 0)
		{
			num_pad = num_pad / 10;
		}
		while (num_pad >= 1)
		{
			_putchar((num / num_pad) + '0');
			num = num % num_pad;
			num_pad = num_pad / 10;
		}
	}
	else
		_putchar('0');
}
