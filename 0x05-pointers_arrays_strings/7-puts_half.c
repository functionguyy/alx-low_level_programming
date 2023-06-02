#include "main.h"

/**
* puts_half - print second half of a string
* @str: char array string type
* Description: if old number of chars, print(length - 1) / 2
*/

void puts_half(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}

	if (i % 2 != 0)
	{
		i = (i + 1) / 2;

		while (str[i] != '\0')
		{
			_putchar(str[i++]);
		}
		_putchar('\n');
	}
	else if (i % 2 == 0)
	{
		i = i / 2;

		while (str[i] != '\0')
		{
			_putchar(str[i++]);
		}
		_putchar('\n');
	}
}
