#include "function_pointers.h"
#include <unistd.h>
/**
 * print_name - a function that prints a nanme
 * @name: pointer to a string
 * @f: pointer to a function that
 *
 * Return: Nothing
 */
void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL)
	{
		f(name);
	}
}
