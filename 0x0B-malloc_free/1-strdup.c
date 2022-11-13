#include <stdlib.h>
/**
 * _strdup - returns a pointer to a newly allocated spcae in memory, which
 * contains a copy of the string given as a parameter.
 * @str: string to be duplicated
 *
 * Return: NULL if str is NULL or memorny is insufficient
 */
char *_strdup(char *str)
{
	unsigned int i;
	unsigned int idx;
	char *p;

	if (str == NULL)
	{
		return (NULL);
	}



	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}

	i++;
	p = malloc(sizeof(char) * i);

	if (p == NULL)
	{
		return (NULL);
	}

	idx = 0;
	while (idx < i)
	{
		p[idx] = str[idx];
		idx++;
	}
	p[i] = '\0';

	return (p);

}
