#include <stdlib.h>
#include <stdio.h>
/**
 * _strlen - count the characters in a string literal
 * @c: pointer to the string literal
 *
 * Return: number of character in the string literal
 */
int _strlen(char *c)
{
	if (*c == '\0')
	{
		return (0);
	}

	return (1 + _strlen(c + 1));
}

/**
 * str_concat - concatenates two strings. If NULL is passed as argument of any
 * of the string pointer parameter, the NULL value is treated as an
 * empty string
 * @s1: pointer to the first string literal
 * @s2: pointer to the second string literal
 *
 * Return: pointer to a newly allocated space in memory which contains the
 * the contents of s1, followed by the contents of s2, and null terminated
 */
char *str_concat(char *s1, char *s2)
{
	char *mem_alloc;
	unsigned int count1, count2, mem_size;
	unsigned int i, j;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	count1 = _strlen(s1);
	count2 = _strlen(s2);

	mem_size = count1 + count2 + 1;

	mem_alloc = malloc(sizeof(char) * mem_size);

	if (mem_alloc == NULL)
		return (NULL);

	i = 0;
	while (i < count1)
	{
		mem_alloc[i] = s1[i];
		i++;
	}

	j = 0;
	while (j <= count2)
	{
		mem_alloc[i] = s2[j];
		i++;
		j++;
	}

	return (mem_alloc);
}
