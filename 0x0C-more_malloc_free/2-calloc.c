#include "main.h"
#include <stdlib.h>
/**
 * _memset - function that fills the first memByte bytes of the memory area
 * pointed to by mem with the constant byte num
 * @mem: pointer to a malloc allocated memory area
 * @num: value to be set in memByte of memory area pointed to by mem
 * @memByte: positive integer
 *
 * Return: mem
 */
void *_memset(void *mem, unsigned int num, unsigned int memByte)
{
	/* decalre variable */
	unsigned char *bytePtr;

	/* initialize variable */
	bytePtr = mem;

	/* set memory bytes */
	while (memByte > 0)
	{
		*bytePtr = (unsigned char)num;
		bytePtr++;
		memByte--;
	}

	/* return to the allocated memory space that passed */
	return (mem);
}
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

	/* set memory to zero */
	memory = _memset(memory, 0, memoryByteSize);

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
