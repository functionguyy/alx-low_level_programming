#include "lists.h"
#include <stdio.h>
/**
 * print_listint - prints all the elements of a singly list
 * @h: pointer to a singly linked list
 *
 * Description: function prints all element of a list of struct type listint_t
 * Return: the number of nodes in the singly linked list
 */
size_t print_listint(const listint_t *h)
{
	/* declare variables */
	size_t n;

	/* initialize variables */
	n = 0;


	/* print all the elements of the singly linked list */
	while (h != NULL)
	{
		printf("%d\n", h->n);
		n++;
		h = h->next;
	}

	return (n);
}
