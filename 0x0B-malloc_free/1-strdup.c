#include "main.h"
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/**
 * _strdup - function that returns a pointer to a newly allocated space in
 * memory, which contains a copy of the string given as a paramater
 * @str: pointer to string
 *
 * Description: function returns a pointer to a new string which is a duplicate
 * of the string str. Memory for the new string is obtained with malloc, and
 * can be freed with free
 * Return: pointer to the duplicated string or NULL otherwise
 */

char *_strdup(char *str)
{
	/* Declare variables */
	int loopIndex, strLength;
	char *newStrMemory;


	/* initializ variables */
	strLength = 0;
	loopIndex = 0;
	newStrMemory = NULL;
	errno = 0;

	/* Confirm value in str is not NULL */
	if (str == NULL)
		return (NULL);

	/* Get the length of string pointed to by str */
	strLength = strlen(str);


	/* Use length of string to request memory allocation */
	newStrMemory = malloc(sizeof(char) * strLength + 1);


	/* confirm that memory allocation was successful */
	if (newStrMemory == NULL || errno == ENOMEM)
		return (NULL);


	/* assign character in string pointed to by str to the new memory */
	while (loopIndex < strLength)
	{
		newStrMemory[loopIndex] = str[loopIndex];
		loopIndex++;
	}

	/* add new string's terminating null byte */
	newStrMemory[strLength] = '\0';

	/* return pointer to the new allocated memory */
	return (newStrMemory);
}
