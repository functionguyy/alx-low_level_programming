#include "main.h"

/**
* print_rev - print a string in reverse
* @s: char array string type
*/

void print_rev(char *s)
{
	int i;
	int j;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}

	j = i - 1;
	while (s[j])
	{
		_putchar(s[j]);
		j--;
	}
	_putchar(10);
}
