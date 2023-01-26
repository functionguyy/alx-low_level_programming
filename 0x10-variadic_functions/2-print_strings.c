#include <stdio.h>
#include <stdarg.h>
/**
*
*
*
*
*/
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list ap;
	unsigned int loop_idx;
	char *sptr;

	va_start(ap, n);
	for (loop_idx = 0; loop_idx < n; loop_idx++)
	{
		sptr = va_arg(ap, char *);
		if (sptr)
		{
			printf("%s", sptr);
		}
		else
		{
			printf("(nil)");
		}

		if (separator && (loop_idx != n - 1))
		{
			printf("%s", separator);
		}
	}
	va_end(ap);
	printf("\n");
}
