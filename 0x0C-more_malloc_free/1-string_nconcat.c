#include "main.h"
#include <stdlib.h>
/**
 * _strlen - function return the number of character bytes in string literal
 * excluding the null byte
 * @s: pointer to a string literal
 *
 * Return: number of character bytes in the string excluding the null byte
 */
int _strlen(char *s)
{
	/* declare variable */
	int strByteCount;


	/* initialize variable */
	strByteCount = 0;

	/* count the character bytes in the string excluding the null byte */
	while (*s != '\0')
	{
		strByteCount++;
		s++;
	}

	/* return number of character bytes in the string */
	return (strByteCount);
}
/**
 * _strncat - function concatenates the string in src to the string in dest,
 * using the most n bytes of src
 * @dest: pointer to the buffer for the concatenated string
 * @src: pointer to the string to be concatenated
 * @n: number of bytes
 *
 * Return: pointer to the result concatenated string in dest
 */
char *_strncat(char *dest, char *src, int n)
{
	/* declare variables */
	int destStrByteCount, index, srcStrByteCount;

	/* initialize variables */
	destStrByteCount = _strlen(dest);
	srcStrByteCount = _strlen(src);
	index = 0;

	/* concat string in src to string in dest */
	if (n >= srcStrByteCount)
	{
		while (index < srcStrByteCount)
		{
			*(dest + destStrByteCount) = *(src + index);
			destStrByteCount++;
			index++;
		}
	}

	if (n < srcStrByteCount)
	{
		while (index < n)
		{
			*(dest + destStrByteCount) = *(src + index);
			destStrByteCount++;
			index++;
		}
	}
	/* null terminate the concatenated string */
	*(dest + destStrByteCount) = '\0';

	return (dest);
}
/**
 * _strcpy - function copies the string pointed to by src, including the
 * terminating null byte('\0'), to the buffer pointed to by dest.
 * @dest: pointer buffer to store the string copied from src
 * @src: pointer to string to be copied
 *
 * Return: pointer to the destination string dest
 */

char *_strcpy(char *dest, char *src)
{
	/* declare variables */
	int index, srcStrByteCount;

	/* initialize variables */
	index = 0;
	srcStrByteCount = _strlen(src);

	/* copy string point to by src into buffer pointed to by dest */
	while (index <= srcStrByteCount)
	{
		*(dest + index) = *(src + index);
		index++;
	}

	return (dest);
}
/**
 * string_nconcat - function that concatenates two strings
 * @s1: pointer to the first string
 * @s2: pointer to the second string
 * @n: number of bytes
 *
 * Description: function creates a newly allocated space in memory, which
 * contains s1, followed by the first n bytes of s2, and null terminated
 * Return: pointer to the newly created string on successful execution or NULL
 * otherwise
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	/* declare variables */
	int strOneByteCount, memoryByteSize;
	char *newStrMemory;

	/* initialize variables */
	strOneByteCount = 0;
	memoryByteSize = 0;
	newStrMemory = NULL;

	/* treat NULL arguments as an empty */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* total byte count of required buffer */
	strOneByteCount = _strlen(s1);
	memoryByteSize = strOneByteCount + n + 1;

	/* use total byte count of required buffer to request memory allocation */
	newStrMemory = malloc(sizeof(char) * memoryByteSize);


	/* confirm memory allocation status */
	if (newStrMemory == NULL)
		return (NULL);

	/* copy s1 into allocated memory */
	newStrMemory = _strcpy(newStrMemory, s1);

	/* concatenate s2 with s1 */
	newStrMemory = _strncat(newStrMemory, s2, n);

	/* return pointer to allocated memory */
	return (newStrMemory);
}

