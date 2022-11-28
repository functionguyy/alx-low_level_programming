#include "dog.h"
#include <stdlib.h>
/**
* init_dog - initialize a variable of type struct dog
* @d: pointer to the struct variable
* @name: value to set struct first member
* @age: value to set struct second member
* @owner: value to set struct third member
*
*
*/

void init_dog(struct dog *d, char *name, float age, char *owner)
{

	struct dog *dog;

	if (d == NULL)
		exit(98);

	dog = d;
	dog->name = name;
	dog->age  = age;
	dog->owner = owner;
}
