#include "main.h"
#include <stdlib.h>

/**
 * create_array - function that creates an array of chars, and initialize it
 * with a specific char
 * @size: integer
 * @c: a character constant
 *
 * Return: pointer to the array or NULL if it fails
 */

char *create_array(unsigned int size, char c)
{
	/* Declare variables */
	char *mem_alloc;
	int loop_idx;

	/* initialize the variables */
	mem_alloc = NULL;
	loop_idx = 0;



	/* confirm the value is variable size is greater than zero */
	if (size == 0)
		return (NULL);


	/* Assign malloc allocated memory to pointer variable */
	mem_alloc = malloc(sizof(char) * size);


	/* check that there was no error in memory allocation */
	if (mem_alloc == NULL)
		return (NULL);


	/* initialize the allocated memory with variable c */
	while (loop_idx < size)
	{
		mem_alloc[loop_idx] = c;
		loop_idx++;
	}


	/* return pointer to the allocated memory */
	return (mem_alloc);
}
