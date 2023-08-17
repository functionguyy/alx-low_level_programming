#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"
/**
 * print_numbers - function that prints numbers, followed by a new line
 * @separator: pointer to string to printed between numbers
 * @n: number of integers passed to the function
 *
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	/* declare variables */
	va_list ap;
	unsigned int idx;

	/* initialize the variables */
	va_start(ap, n);
	idx = 0;

	/* confirm non-null and non-zero paramter */
	if (n == 0)
		return;

	/* print all the variadic parameters passed */
	while (idx < n)
	{
		printf("%d", va_arg(ap, int));
		if (separator != NULL && idx != n - 1)
			printf("%s", separator);
		idx++;
	}
	/* print a new line at the end */
	putchar('\n');
}
