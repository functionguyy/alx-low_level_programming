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
		if (!(d->name) && d->age && d->owner)
			printf("Name: (nil)\nAge: %.6f\nOwner: %s\n", d->age,
					d->owner);
		else if (d->name && !(d->age) && d->owner)
			printf("Name: %s\nAge: (nil)\nOwner: %s\n", d->name,
					d->owner);
		else if (d->name && d->age && !(d->owner))
			printf("Name: %s\nAge: %.6f\nOwner: (nil)", d->name, d->age);
		else
			printf("Name: %s\nAge: %.6f\nOwner: %s\n", d->name,
					d->age, d->owner);
	}
}
