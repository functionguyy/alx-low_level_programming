#include "dog.h"
#include <stdlib.h>
#include <string.h>
/**
 * new_dog - Function that creates a new dog struct data
 * @name:  value for the name member of the struct
 * @age: value  for the age member of the struct
 * @owner: value of the owner member of the struct
 *
 * Return: pointer to the newly created struct on success or NULL on failure
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *mem_alloc;


	mem_alloc = malloc(sizeof(dog_t));
	if (mem_alloc == NULL)
	{
		free(mem_alloc);
		return (NULL);
	}

	mem_alloc->name = strdup(name);
	mem_alloc->age = age;
	mem_alloc->owner = strdup(owner);

	return (mem_alloc);
}
