#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * print_strings - function that prints strings, followed by a new line
 * @separator: pointer to the string to be printed between the strings
 * @n: the number of strings passed to the function
 *
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	/* declare variables */
	va_list ap;
	unsigned int idx;
	char *argStr;

	/* initialize the variables */
	va_start(ap, n);
	idx = 0;


	/* print all the variadic parameter passed */
	while (idx < n)
	{
		argStr = va_arg(ap, char *);
		if (argStr == NULL)
			printf("(nil)");
		else
			printf("%s", argStr);
		if (separator != NULL && idx != n - 1)
			printf("%s", separator);

		idx++;
	}

	/* print a new line */
	putchar('\n');

	/* clean up the variadic argument list */
	va_end(ap);
}
