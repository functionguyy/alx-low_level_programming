#include <stdlib.h>
/**
* _calloc - allocates memory for an array using malloc
* @nmemb: size of type memory byte
* @size: number of elements
*
* Description: The calloc function allocates memory for an array of nmemb
* elements of size bytes each and returns a pointer to the allocated memory.
* The is set to zero.
* Return: returns pointer to the allocated memory. returns NULL if nmemb or
* size or malloc fails.
*/
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *m;
	int i;

	if ((nmemb == 0) || (size == 0))
		return (NULL);

	m = malloc(nmemb * size);
	if (m == NULL)
		return (NULL);
	
	i = 0;
	while (i < size)
	{
		m[i] = 0;
		i++;
	}

	return (m);
}
