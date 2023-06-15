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
	char *dog_name, *dog_owner;
	char *dest_name, *dest_owner;
	int len_owner, len_name;



	mem_alloc = malloc(sizeof(dog_t));
	if (mem_alloc == NULL)
		return (NULL);
	len_name = strlen(name) + 1;
	len_owner = strlen(owner) + 1;

	dest_name = malloc(sizeof(char) * len_name);
	if (dest_name == NULL)
	{
		free(mem_alloc);
		return (NULL);
	}

	dest_owner = malloc(sizeof(char) * len_owner);
	if (dest_owner == NULL)
	{
		free(dest_name);
		free(mem_alloc);
		return (NULL);
	}

	dest_name = strcpy(name);
	dest_owner = strcpy(owner);

	mem_alloc->name = dest_name;
	mem_alloc->age = age;
	mem_alloc->owner = dest_owner;


	return (mem_alloc);
}
