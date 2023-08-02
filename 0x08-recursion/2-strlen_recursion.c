#include "main.h"
/**
 * _strlen_recursion - Function that returns the length of a string
 * @s: string
 *
 * Return: the numbers of characters in a string
 */

int _strlen_recursion(char *s)
{

	if (*s != '\0')
	{
		return (_strlen_recursion(s + 1) + 1);
	}
	else
		return (0);
}
