#include "main.h"
#include <stdlib.h>
#include <string.h>
/**
 * concat - function that concatenates to a new memory
 * @memory: memory space to store the concatenated string
 * @size: count of the strings to be concatenated
 * @arr: array of pointers to the string to be concatenated
 *
 */

void concat(char *memory, char **arr, int size)
{
	int index;
	char *temp, *str;

	index = 0;
	temp = memory;
	while (index < size)
	{
		str = arr[index];
		while (*str != '\0')
		{
			*temp = *str;
			temp++;
			str++;
		}
		*temp++ = '\n';
		index++;
	}
}


/**
 * argstostr - function that concatenates all the arguments of your program
 * @ac: count of the command-line passed to the string
 * @av: array of pointer to the strings of all the argument supplied to the
 * program
 *
 * Return: a pointer to a new string or NULL otherwise
 */
char *argstostr(int ac, char **av)
{
	/* Declare variables */
	int loopIndex, totalLen;
	char *newStrMemory;


	/* initialize variables */
	loopIndex = 0;
	totalLen = 0;
	newStrMemory = NULL;

	/* confirm that command line arguments were passed to the program */
	if (ac == 0 || av == NULL)
		return (NULL);

	/* get the total length of the strings passed as command-line arguments */
	while (loopIndex < ac)
	{
		totalLen += strlen(av[loopIndex]) + 1;
		loopIndex++;
	}

	/* use total length of the strings to request memory allocation */
	newStrMemory = malloc(sizeof(char) * totalLen);

	/* confirm the memory allocation status */
	if (newStrMemory == NULL)
		return (NULL);

	/* concatenate all the string argument */
	concat(newStrMemory, av, ac);
	return (newStrMemory);
}
