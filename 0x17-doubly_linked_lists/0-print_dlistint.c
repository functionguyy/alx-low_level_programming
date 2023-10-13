#include <stdio.h>
#include "lists.h"
#include <stdlib.h>
/**
 * print_dlistint - function that prints all the elements of a dlistint_t list
 * @h: head pointer of dlistint_t list
 *
 * Return: the number of nodes in the list
 */


size_t print_dlistint(const dlistint_t *h)
{
	size_t node_count;

	node_count = 0;
	if (h)
	{
		while (h != NULL)
		{
			printf("%d\n", h->n);
			node_count++;
			h = h->next;
		}
	}

	return (node_count);
}
