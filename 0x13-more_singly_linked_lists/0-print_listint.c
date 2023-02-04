#include <stdio.h>
#include <stddef.h>
#include "lists.h"
/**
* print_listint - function prints all the elements of a linked list.
* @h: pointer to linked list
*
* Description: function prints all elements of a list of struct type listint_t
* Return: the numbers nodes in the linked list
*/
size_t print_listint(const listint_t *h)
{
	unsigned int n;

	n = 0;
	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		n++;
	}
	return (n);
}
