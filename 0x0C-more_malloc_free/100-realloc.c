#include "main.h"
#include <stdlib.h>
/**
 * _memcpy - function copies n bytes from memory area oldMemoryPtr to memory
 * area newMemoryPtr
 * @newMemoryPtr: pointer to memory area allocated with malloc
 * @oldMemoryPtr: pointer to memory area allocated with malloc
 * @n: number of bytes
 *
 * Return: newMemoryPtr
 */
void *_memcpy(void *newMemoryPtr, void *oldMemoryPtr, size_t n)
{
	/* declare variables */
	char *oldMemPtr, *newMemPtr;
	size_t index;

	/* initialize variables */
	oldMemPtr = oldMemoryPtr;
	newMemPtr = newMemoryPtr;
	index = 0;

	/* copy n bytes from oldMemory area to newMemory area */
	while (index < n)
	{
		*(newMemPtr + index) = *(oldMemPtr + index);
		index++;
	}


	/* return pointer to newMemory area */
	return (newMemoryPtr);
}
/**
 * _realloc - function that reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated with malloc
 * @old_size: size in bytes of the allocated space for ptr
 * @new_size: size in bytes of the new memory block
 *
 * Return: if successful, return pointer to new memory block or NULL otherwise
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	/* declare variables */
	void *newMemory;

	/* initialize variables */
	newMemory = NULL;


	/* confirm new_size not equal to old_size and ptr not equal to NULL */
	if (new_size == old_size && ptr != NULL)
		return (ptr);

	/* confirm new_size not equal to zero and ptr not equal to NULL */
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	/* use new_size to request memory allocation */
	newMemory = malloc_checked(new_size);

	/* confirm ptr not equal to NULL */
	if (ptr == NULL)
	{
		ptr = newMemory;
		return (ptr);
	}


	/* copy bytes in old_size memory area to new_size memory area */
	newMemory = _memcpy(newMemory, ptr, old_size);

	/* release the previous ptr memory area */
	free(ptr);

	/* return pointer to allocated memory */
	return (newMemory);
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
