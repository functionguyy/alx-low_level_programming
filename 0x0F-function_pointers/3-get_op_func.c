#include "3-calc.h"
#include <stddef.h>
/**
 * _strcmp - function compares two strings
 * @s1: pointer to the first string
 * @s2: pointer to the second string
 *
 * Return: integer less than, equal to, or greater than zero if s1 is found,
 * respectively, to be less than, to match, or be greater than s2.
 */
int _strcmp(char *s1, char *s2)
{
	/* declare variables */
	int matchValue, loopIndex;

	/* initialize variables */
	matchValue = 0;
	loopIndex = 0;

	/* compare the characters of each string */
	while (matchValue == 0 && s1[loopIndex] != '\0' && s2[loopIndex] != '\0')
	{
		if (s1[loopIndex] < s2[loopIndex])
			matchValue = s1[loopIndex] - s2[loopIndex];

		if (s1[loopIndex] > s2[loopIndex])
			matchValue = s1[loopIndex] - s2[loopIndex];

		loopIndex++;
	}

	return (matchValue);
}
/**
 * _strlen - functions return the length of a string
 * @s: pointer to the string to be counted
 *
 * Return: returns the length of the string pointed to by s
 */
int _strlen(char *s)
{
	/* declare variables */
	int charByteCount;

	/* initialize variables */
	charByteCount = 0;

	/* count numbers of character bytes in string */
	while (*s != '\0')
	{
		charByteCount++;
		s++;
	}

	return (charByteCount);
}

/**
 * get_op_func - function that selects the correct function to perform the
 * operation asked by the user
 * @s: pointer to the operator passed as argument to the program
 *
 *
 * Return: pointer to the function that corresponds to the operator given as a
 * parameter or NULL if there is no operator match
 */
int (*get_op_func(char *s))(int, int)
{
	/* declare variables */
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i;

	/* initialize variable */
	i = 0;

	/* get function based on operator passed */
	while (ops[i].op != NULL)
	{
		if (_strcmp(ops[i].op, s) == 0 && _strlen(s) < 2)
		{
			return (ops[i].f);
		}
		i++;
	}

	return (NULL);
}
