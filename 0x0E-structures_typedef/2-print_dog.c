#include <stdio.h>
#include <stdlib.h>
#include "dog.h"
/**
* print_dog - prints the member values of a variable of type struct dog
* @d: pointer to the struct dog variable
*
*/

void print_dog(struct dog *d)
{

	if (d)
	{
		(d->name) ? printf("Name: %s\n", d->name) : printf("Name: (nil)\n");
		(d->age) ? printf("Age: %.f\n", d->age) : printf("Age: (nil)\n");
		(d->owner) ? printf("Owner: %s\n", d->owner) : printf("Owner: (nil)\n");

	}
}
