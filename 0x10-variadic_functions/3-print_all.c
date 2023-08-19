#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
/**
 * printMatch - functions print the variadic argument that matches the format
 * character
 * @s: pointer to format character
 * @arg: variadic argument;
 */
void printMatch(const char *s, va_list arg)
{
	/* declare variables */
	char *arr[] = {"c", "i", "f", "s"};

	int i;
	char *str;


	i = 0;
	str = NULL;


	while (*(arr[i]) != *s)
	{
		i++;
	}

	switch (*(arr[i]))
	{
		case 'c':
			printf("%c", va_arg(arg, int));
			break;
		case 'i':
			printf("%d", va_arg(arg, int));
			break;
		case 'f':
			printf("%f", va_arg(arg, double));
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
	}
}
/**
 * printComma - function prints a comman based on the signal and character
 * passed to it.
 * @sig: integer number
 * @c: character constant
 *
 * Description: if sig is 1 and character is not a null byte the function
 * prints a comma
 */
void printComma(int sig, char c)
{
	switch (sig)
	{
		case 1:
			switch (c)
			{
				case '\0':
					return;
				default:
					printf(", ");
			}
		case 0:
			return;

	}
}
/**
 * ifNull- terminates the current running process if argument is NULL or an
 * empty string
 * @fmt: pointer to the argument string
 */
void ifNull(const char *fmt)
{
	if (fmt == NULL || *fmt == '\0')
	{
		putchar('\n');
		exit(EXIT_SUCCESS);
	}
}
/**
 * print_all - function that prints anything
 * @format: list of types of arguments passed to the function
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	int idx, foundMatch;

	idx = 0;
	foundMatch = 0;
	va_start(ap, format);

	ifNull(format);

	while (*(format + idx) != '\0')
	{
		foundMatch = 0;
		switch (*(format + idx))
		{
			case 'c':
				foundMatch = 1;
				printMatch((format + idx), ap);
				break;
			case 'i':
				foundMatch = 1;
				printMatch((format + idx), ap);
				break;
			case 'f':
				foundMatch = 1;
				printMatch((format + idx), ap);
				break;
			case 's':
				foundMatch = 1;
				printMatch((format + idx), ap);
				break;
			default:
				idx++;
				continue;
		}
		idx++;
		printComma(foundMatch, *(format + idx));
	}

	putchar('\n');
}




