#include "lists.h"
#include <stdio.h>
/**
 * print_list - prints all the element of a list_t list
 * @h: pointer to list_t list
 *
 * Return: the number of nodes in list_t list.
 */
size_t print_list(const list_t *h)
{
	/* declare variables */
	size_t idx;


	/* initialize variables */
	idx = 0;


	/* confirm list */
	if (h == NULL || h->next == NULL)
		return (idx);

	/* print elements of the linked list */
	while (h != NULL)
	{
		if (h->str == NULL)
		{
			printf("[%d] (nil)\n", 0);
			n++;
			h = h->next;
			continue;
		}

		printf("[%d] %s\n", h->len, h->str);
		n++;
		h = h->next;
	}

	return (idx);
}
