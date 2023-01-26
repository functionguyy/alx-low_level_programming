#include <stdio.h>
#include <stdarg.h>
/**
* print_strings - function that prints strings, followed by a new line
* @separator: the string to be printed between the strings
* @n: the number of strings passed to the function
*
* Description: if separator is NULL don't print it. If one string is NULL
* print (nil) instead
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
