#include "main.h"

/**
* rev_string - reverse a string
* @s: char array string type
*/

void rev_string(char *s)
{
	int i;
	int j;
	char c;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}

	j = i - 1;
	i = 0;
	while (i < j)
	{
		c = s[j];
		s[j] = s[i];
		s[i] = c;

		i++;
		j--;
	}
}
