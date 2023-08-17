#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
/**
 * print_all - function that prints anything
 * @format: list of types of arguments passed to the function
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	char *str;
	int idx, strByteCount;

	str = NULL;
	idx = 0;
	va_start(ap, format);

	strByteCount = strlen(format);
	while (*(format + idx) != '\0')
	{
		switch (*(format + idx))
		{
			case 'c':
				printf("%c", va_arg(ap, int));
				break;
			case 'i':
				printf("%d", va_arg(ap, int));
				break;
			case 'f':
				printf("%g", va_arg(ap, double));
				break;
			case 's':
				str = va_arg(ap, char *);
				if (str != NULL)
					printf("%s", str);
				else
					printf("(nil)");
				break;
			default:
				idx++;
				continue;
		}
		if (idx != strByteCount - 1)
			printf(", ");
		idx++;
	}
	putchar('\n');

}
