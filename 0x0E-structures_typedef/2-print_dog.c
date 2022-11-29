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
		if (!d->name)
			printf("Name: (nil)");
		if (!d->age)
			printf("Age: (nil)");
		if (!d->owner)
			printf("Owner: (nil)");
		printf("Name: %s\nAge: %.6f\nOwner: %s\n", d->name, d->age,
				d->owner);
	}
}
