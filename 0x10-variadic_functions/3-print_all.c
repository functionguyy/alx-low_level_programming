#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
/**
 * _strlen - function return the numbers of character byte in a string
 * @s: pointer to the string whose character byte should be counted
 *
 * Return: number of character byte in the string
 */
int _strlen(const char *s)
{
	/* declare variables */
	int strByteCount;

	/* initialize variable */
	strByteCount = 0;

	/* count number of character byte in string */
	while (*(s + strByteCount) != '\0')
		strByteCount++;

	/* return number of character bytes in string */
	return (strByteCount);
}
/**
 * printIfMatch - function checks prints the value that matches the characters
 * in a format string
 * @fmt: pointer to format string
 * @arg: argument list of parameters to printed for each respective matching
 * characters in fmt
 * @len: the length of fmt
 *
 */
void printIfMatch(const char *fmt, va_list arg, int len)
{
	/* declare variables */
	int idx;
	char *str;

	/* initialize variable */
	idx = 0;
	str = NULL;

	/* confirm character match */
	while (*(fmt + idx) != '\0')
	{
		switch (*(fmt + idx))
		{
			case 'c':
				printf("%c", va_arg(arg, int));
				break;
			case 'i':
				printf("%d", va_arg(arg, int));
				break;
			case 'f':
				printf("%g", va_arg(arg, double));
				break;
			case 's':
				str = va_arg(arg, char *);
				if (str != NULL)
				{
					printf("%s", str);
					break;
				}
				printf("(nil)");
				break;
			default:
				idx++;
				continue;
		}
		if (idx != len - 1)
			printf(", ");
		idx++;
	}
}
/**
 * print_all - function that prints anything
 * @format: list of types of arguments passed to the function
 */
void print_all(const char * const format, ...)
{
	/* declare variables */
	va_list ap;
	int strByteCount;

	/* initialize variables */
	va_start(ap, format);
	strByteCount = _strlen(format);

	/* print match */
	printIfMatch(format, ap, strByteCount);
	/* print new line */
	putchar('\n');

}
