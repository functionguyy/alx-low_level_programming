#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
/**
 * printChar - print matching character
 * @arg: argument list
 */
void printChar(va_list arg)
{
	printf("%c", va_arg(arg, int));
}
/**
 * printInt - print matching integer
 * @arg: argument list
 */
void printInt(va_list arg)
{
	printf("%d", va_arg(arg, int));
}
/**
 * printFloat - printing floating
 * @arg: argument list
 */
void printFloat(va_list arg)
{
	printf("%g", va_arg(arg, double));
}
/**
 * printStr - print string
 * @arg: argument list
 */
void printStr(va_list arg)
{
	char *str;

	str = NULL;

	str = va_arg(arg, char *);
	if (str != NULL)
	{
		printf("%s", str);
		return;
	}
	printf("(nil)");
}
/**
 * print_all - function that prints anything
 * @format: list of types of arguments passed to the function
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	int idx, arrIdx;
	fStr_t arr[] = {
		{"c", printChar},
		{"i", printInt},
		{"f", printFloat},
		{"s", printStr},
		{NULL, NULL}
	};

	idx = 0;
	arrIdx = 0;
	va_start(ap, format);

	while (*(format + idx) != '\0')
	{
		arrIdx = 0;
		while (*(arr[arrIdx].fmt) != *(format + idx))
			arrIdx++;
		arr[arrIdx].f(ap);
		idx++;
		if (*(format + idx) != '\0')
			printf(", ");
	}

	putchar('\n');
}


