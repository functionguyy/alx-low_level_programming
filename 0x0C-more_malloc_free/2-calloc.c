#include "main.h"
#include <stdlib.h>
/**
 * _calloc - function that allocates memory for an array, using malloc
 * @nmemb: number of memory bytes
 * @size: size of element byte
 *
 * Return: pointer to allocated memory or NULL otherwise
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	/* declare variables */
	void *memory;
	unsigned int memoryByteSize;

	/* initialize variables */
	memory = NULL;

	/* check for zero value arguments */
	if (nmemb == 0 || size == 0)
		return (NULL);

	/* get total memory byte size */
	memoryByteSize = nmemb * size;

	/* use total memeory byte size to request memory allocation */
	memory = malloc_checked(memoryByteSize);

	/* return pointer to the allocated memory */
	return (memory);
}
/**
 * malloc_checked - function that allocates memory using malloc
 * @b: size of the memory bytes to be allocated
 *
 * Return: pointer to the allocated memory
 */
void *malloc_checked(unsigned int b)
{
	/* declare variable */
	void *memory;

	/* initialize variable */
	memory = NULL;

	/* request memory allocation */
	memory = malloc(b);

	/* confirm memory allocation status */
	if (memory == NULL)
		exit(98);

	/* return pointer to allocated memory */
	return (memory);
}
