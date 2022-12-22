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

	if (n < 0)
	{
		_putchar('-');
		num = -num;
	}

	if ((num / 10) > 0)
		print_number(num / 10);

	_putchar((num % 10) + '0');
}
