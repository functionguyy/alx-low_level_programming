#include <stdio.h>
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
		if (d->name)? printf("Name: %s\n", d->name): printf("Name: (nil)\n");
		if (d->age)? printf("Age: %.6f\n", d->age): printf("Age: (nil)\n");
		if (d->owner)? printf("Owner: %s\n", d->owner): printf("Owner: (nil)\n");

	}
}
