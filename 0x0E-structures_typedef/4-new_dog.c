#include "dog.h"
#include <stdlib.h>
/**
 * _strlen - calculate the length of a string
 * @s: pointer to string whose length should be calculated
 *
 * Description: function calulates the length of the string pointed to by s,
 * exculidng the terminating null byte
 * Return: length of the string.
 */
int _strlen(char *s)
{
	/* declare variable */
	int strByteCount;

	/* initialize variable */
	strByteCount = 0;

	/* count number of bytes in string */
	while (*s != '\0')
	{
		strByteCount++;
		s++;
	}

	/* return byte count */
	return (strByteCount);
}

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
	/* declare variables */
	dog_t *dogStruct;

	/* initialize variable */
	dogStruct = NULL;




	/* allocte memory for the struct */
	dogStruct = malloc(sizeof(dog_t));
	if (dogStruct == NULL)
		return (NULL);



	/* allocate memory for the  members of the struct */
	dogStruct->name = malloc(sizeof(char) * _strlen(name) + 1);
	if (dogStruct->name == NULL)
	{
		free(dogStruct);
		return (NULL);
	}

	dogStruct->owner = malloc(sizeof(char) * _strlen(owner) + 1);
	if (dogStruct->owner == NULL)
	{
		free(dogStruct->name);
		free(dogStruct);
		return (NULL);
	}

	/* assigne values to the members of the struct */
	strcpy(dogStruct->name, name);
	strcpy(dogStruct->owner, owner);
	dogStruct->age = age;


	/* return pointer to the created struct */
	return (dogStruct);
}
