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
	dog_t *dog_struct;
	unsigned int len_str1, len_str2;




	dog_struct = malloc(sizeof(dog_t));
	if (dog_struct == NULL)
		return (NULL);

	len_str1 = strlen(name);
	len_str2 = strlen(owner);



	dog_struct->name = malloc(sizeof(char) * (len_str1 + 1));
	if (dog_struct->name == NULL)
	{
		free(dog_struct);
		return (NULL);
	}

	dog_struct->owner = malloc(sizeof(char) * (len_str2 + 1));
	if (dog_struct->owner == NULL)
	{
		free(dog_struct->name);
		free(dog_struct);
		return (NULL);
	}

	strcpy(dog_struct->name, name);
	strcpy(dog_struct->owner, owner);
	dog_struct->age = age;


	return (dog_struct);
}
