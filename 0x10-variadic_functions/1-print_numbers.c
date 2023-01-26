#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"
/**
* print_numbers - print numbers, followed by new line
* @separator: string to be printed between numbers
* @n: number of integers passed to the function
*
* Return: Nothing
*
*/

void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list ap;
	unsigned int loop_idx;
	int num;


	va_start(ap, n);
	for (loop_idx = 0; loop_idx < n; loop_idx++)
	{
		num = va_arg(ap, int);
		printf("%d", num);
		if (separator && (loop_idx != n - 1))
		{
			printf("%s", separator);
		}
	}
	va_end(ap);
	printf("\n");
}
