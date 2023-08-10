#include "main.h"
#include <stdlib.h>
/**
 * malloc_checked - function that allocates memory using
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
