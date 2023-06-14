#include "dog.h"
#include <stdio.h>
#include <stdlib.h>
/**
* print_dog - prints the member values of a variable of type struct dog
* @d: pointer to the struct dog variable
*
*/

void print_dog(struct dog *d)
{

	if (d == NULL)
	{
		return;
	}
	else
	{
		if (d->name == NULL)
			printf("Name: (nil)\n");
		else
			printf("Name: %s\n", d->name);
		if (d->age < 0)
			printf("Age: (nil)\n");
		else
			printf("Age: %.6f\n", d->age);
		if (d->owner == NULL)
			printf("Owner: (nil)\n");
		else
			printf("Owner: %s\n", d->owner);
	}
}
