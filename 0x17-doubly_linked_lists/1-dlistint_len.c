#include <stdio.h>
#include "lists.h"
#include <stdlib.h>
/**
 * dlistint_len - function that returns the number of elements in a linked
 * dlistint_t list
 * @h: head pointer of dlistint_t list
 *
 * Return: the number of nodes in the list
 */


size_t dlistint_len(const dlistint_t *h)
{
	size_t node_count;

	node_count = 0;
	if (h)
	{
		while (h != NULL)
		{
			node_count++;
			h = h->next;
		}
	}

	return (node_count);
}
