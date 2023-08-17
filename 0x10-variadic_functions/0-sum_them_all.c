#include <stdarg.h>
#include "variadic_functions.h"
/**
 * sum_them_all - function returns the sum of all its parameter
 * @n: number of parameters
 *
 * Return: the sum of all its parameter
 *
 */
int sum_them_all(const unsigned int n, ...)
{
	/* declare variables */
	va_list ap;
	unsigned int idx, total;

	/* initialize variables */
	va_start(ap, n);
	idx = 0;
	total = 0;

	/* confirm last is non-zero value */
	if (n == 0)
		return (0);

	/* sum all the arguments passed */
	while (idx < n)
	{
		total += va_arg(ap, int);
		idx++;
	}

	/* clean up the variadic argument list */
	va_end(ap);

	return (total);
}
