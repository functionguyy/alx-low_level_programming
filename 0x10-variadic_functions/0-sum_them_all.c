#include <stdarg.h>
/**
* sum_them_all - sum all of its parameter
* @n: number of variable argument
*
* Return: sum of all its paramters or 0
*/

int sum_them_all(const unsigned int n, ...)
{
	if (n != 0)
	{
		va_list ap;
		unsigned int loop_idx;
		int sum;


		va_start(ap, n);
		sum = 0;
		for (loop_idx = 0; loop_idx < n; loop_idx++)
		{
			sum = sum + va_arg(ap, int);
		}
		va_end (ap);
		return (sum);

	}
	return (0);
}
