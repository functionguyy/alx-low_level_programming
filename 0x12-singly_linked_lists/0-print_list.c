#include "lists.h"
/**
 * print_list - prints all the element of a list_t list
 * @h: pointer to list_t list
 *
 * Return: the number of nodes in list_t list.
 */
size_t print_list(const list_t *h)
{
	/* declare variables */
	unsigned int n;


	/* initialize variables */
	n = 0;


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

	return (n);
}
