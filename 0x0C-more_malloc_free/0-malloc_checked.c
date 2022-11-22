#include <stdlib.h>
/**
* malloc_checked - allocates memory using malloc
* @b: type byte size
*
* Return: pointer to allocated memory
*/
void *malloc_checked(unsigned int b)
{
	void *m; 
	
	m = malloc(b);

	if (m == NULL)
	{
		exit(98);
	}
	return (m);
}
